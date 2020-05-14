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
const int N = 3e5, M = N;

vector<int> g[N];
int DP[N];
stack<int> topSort;
int parent[N];

void ipgraph(int n, int m) {
    int i, u, v;
    while (m--) {
        cin >> u >> v;
        g[u].push_back(v);
    }
}

void dfs_topSort(int u, int par) {
    for (int v : g[u]) {
        if (parent[v]) continue;
        parent[v] = u;
        dfs_topSort(v, u);
    }
    topSort.push(u);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ipgraph(n, m);
    for (int i = 1; i <= n; ++i) {
        if (parent[i]) continue;
        parent[i] = -1;
        dfs_topSort(i, -1);
    }
    while (!topSort.empty()) {
        cout << topSort.top() << '\n';
        topSort.pop();
    }
    return 0;
}