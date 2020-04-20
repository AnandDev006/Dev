/*
    author : Anand

*/

// #include <bits/stdc++.h>

#include <math.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

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

using namespace std;

const int INF = 1e9 + 5;
const int mod = 1000000007;
const double zero = 10e-9;
const int N = 3e5, M = N;

int DP[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int x;
    multiset<int, greater<int>> s;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        s.insert(x);
    }
    sort(a, a + n, greater<int>());
    auto it = s.begin();
    int p = 0;
    int d = 0;
    if (a[p] <= *it) {
        d = s.count(*it);
        it++;
    } else {
        cout << "-1\n";
        return 0;
    }
    int ans = 0;
    int f = 0;
    while (p < n && it != s.end()) {
        int c = 0;
        if (*it < a[p]) {
            f++;
            while (*it < a[p]) {
                p++;
                c++;
            }
        }
        ans += ((2 * (c / d)) - 1);
        ans += ((c % d) != 0 ? 2 : 0);
        d = s.count(*it);
        it = s.upper_bound(*it);
    }
    int rem = n - p;
    int pL = s.size() - f;
    pL += min(rem - pL, f);
    ans += pL;
    ans += ((2 * ((n - p) / pL)) - 1);
    cout << ans << endl;
    return 0;
}