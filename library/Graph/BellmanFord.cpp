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

vector<pair<int, pair<int, int>>> g;  // edgelist
int dist[N];
int parent[N] = {-1};

void ipgraph(int n, int m) {
    int i, u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        g.push_back({w, {u, v}});
        g.push_back({w, {v, u}});  // undirected
    }
}

void bellmanFord(int x, int n) {
    for (int i = 1; i <= n; ++i) dist[i] = INT_MAX;
    dist[x] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        bool flag = false;
        for (auto e : g) {
            int w = e.first;
            int a = e.second.first;
            int b = e.second.second;
            if (dist[a] != INT_MAX && w != INT_MAX && dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                parent[b] = a;
                flag = true;
            }
        }
        if (!flag) break;
    }

    for (auto e : g) {
        int w = e.first;
        int a = e.second.first;
        int b = e.second.second;
        if (dist[b] > dist[a] + w) {
            cout << "-ve weight CYCLE detected\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ipgraph(n, m);
    bellmanFord(1, n);
    for (int i = 1; i <= n; ++i) {
        cout << i << " : " << dist[i] << '\n';
    }

    return 0;
}