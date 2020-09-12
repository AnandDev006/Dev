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
bool visited[N];
int parent[N] = {-1};
int DP[N];

void ipgraph(int n, int m) {
    int i, u, v;
    while (m--) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void dfs(int u, int par = -1) {
    for (int v : g[u]) {
        if (v == par) continue;
        visited[v] = true;
        parent[v] = u;
        dfs(v, u);
    }
}

void bfs(int u) {
    queue<int> Q;
    Q.push(u);
    while (!Q.empty()) {
        int p = Q.front();
        Q.pop();
        for (int v : g[p]) {
            if (v == p) continue;
            visited[v] = true;
            parent[v] = p;
            Q.push(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
