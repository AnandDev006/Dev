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
vector<pair<int, pair<int, int>>> MST;
int DP[N];

void ipgraph(int n, int m) {
    int i, u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
}

void Prim(int n, int m) {
    priority_queue<pair<int, pair<int, int>>> q;
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, INT_MAX);

    q.push({0, {1, 1}});
    dist[1] = 0;

    while (!q.empty()) {
        auto e = q.top();
        q.pop();
        int u = e.second.second;

        if (visited[u]) continue;
        visited[u] = true;
        MST.push_back({-e.first, e.second});

        for (auto E : g[u]) {
            int w = E.second;
            int v = E.first;

            if (dist[v] > w) {
                dist[v] = w;
                q.push({-w, {u, v}});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ipgraph(n, m);
    Prim(n, m);
    for (auto e : MST) {
        int a = e.second.first;
        int b = e.second.second;
        int w = e.first;
        printf("%d-%d : %d\n", a, b, w);
    }
    return 0;
}