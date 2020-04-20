/*
    author : Anand

*/

// #include <bits/stdc++.h>

#include <math.h>

#include <algorithm>
// #include <bitset>
// #include <functional>
#include <iostream>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <utility>
// #include <vector>

#define sz(a) int((a).size())
#define ll long long
#define pb push_back
#define mp(a, b) make_pair(ll(a), ll(b))
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

using namespace std;

// typedef pair<int, int> pi;
// typedef pair<ll, ll> pl;
// typedef vector<int> vi;
// typedef vector<ll> vl;
// typedef vector<pi> vpi;
// typedef vector<pl> vpl;

const int INF = 1e9 + 5;
const int mod = 1000000007;
const double zero = 10e-9;
const int N = 5e5 + 5, M = N;

struct node {
    int L, R, i;
} q[N];

int a[N], h[N], ans[N], cnt[N];
int BLOCK;
int wrong;

bool cmp(node x, node y) {
    if (x.L / BLOCK != y.L / BLOCK) {
        // different blocks, so sort by block.
        return x.L / BLOCK < y.L / BLOCK;
    }
    // same block, so sort by R value
    return x.R < y.R;
}

void add(int position) {
    if (cnt[a[position]] == 0 || cnt[a[position]] == h[a[position] - 1]) {
        wrong++;
    }
    cnt[a[position]]++;
    if (cnt[a[position]] == 0 || cnt[a[position]] == h[a[position] - 1]) {
        wrong--;
    }
}

void remove(int position) {
    if (cnt[a[position]] == 0 || cnt[a[position]] == h[a[position] - 1]) {
        wrong++;
    }
    cnt[a[position]]--;
    if (cnt[a[position]] == 0 || cnt[a[position]] == h[a[position] - 1]) {
        wrong--;
    }
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    BLOCK = sqrt(n) + 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &h[i]);
    }
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &q[i].L, &q[i].R);
        q[i].L--;
        q[i].R--;
        q[i].i = i;
    }
    sort(q, q + t, cmp);
    int currentL = 0, currentR = 0;
    for (int i = 0; i < t; i++) {
        int L = q[i].L, R = q[i].R;
        while (currentR <= R) {
            add(currentR);
            currentR++;
        }
        while (currentR > R + 1) {
            remove(currentR - 1);
            currentR--;
        }
        while (currentL < L) {
            remove(currentL);
            currentL++;
        }
        while (currentL > L) {
            add(currentL - 1);
            currentL--;
        }
        ans[q[i].i] = (wrong == 0);
    }
    for (int i = 0; i < t; ++i) {
        printf("%d\n", ans[i]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}