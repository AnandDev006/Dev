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

vector<pair<int, int>> g[N];
int parent[N] = {-1};
int dist[N];
int DP[N];

void ipgraph(int n, int m) {
    int i, u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});  // undirected
    }
}

void dijkstra(int x, int n) {
    bool processed[n + 1];
    for (int i = 1; i <= n; ++i) {
        processed[i] = false;
        dist[i] = INT_MAX;
    }

    priority_queue<pair<int, int>> q;
    q.push({0, x});
    dist[x] = 0;

    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto v : g[a]) {
            int b = v.first;
            int w = v.second;
            if (dist[a] != INT_MAX && w != INT_MAX && dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                parent[b] = a;
                q.push({-dist[b], b});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ipgraph(n, m);
    dijkstra(1, n);
    for (int i = 1; i <= n; ++i) {
        cout << i << " : " << dist[i] << '\n';
    }
    return 0;
}