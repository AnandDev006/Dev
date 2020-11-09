/*
  author : Anand
*/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "\t" << #__VA_ARGS__ << " : " << (__VA_ARGS__) << endl;
#else
#define debug(...) 42
#endif

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const int N = 1e7;
const int K = 25;

vector<int> a(N);
vector<int> dp(N);
int n;

vector<pair<int, int>> parent;
vector<int> rnk;

void makeSet(int v) {
    parent[v] = {v, 0};
    rnk[v] = 0;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int len = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second += len;
    }
    return parent[v];
}

bool union_sets(int a, int b) {
    a = find_set(a).first;
    b = find_set(b).first;
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = {a, 1};
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
    return false;
}

void solve() {
    
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}