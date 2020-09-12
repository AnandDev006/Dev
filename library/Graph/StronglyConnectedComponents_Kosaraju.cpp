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
vector<int> g_rev[N];
vector<vector<int>> components;
int numOfComponents;
int DP[N];
stack<int> nodes;
vector<bool> visited(N);

void ipgraph(int n, int m) {
    int i, u, v;
    while (m--) {
        cin >> u >> v;
        g[u].push_back(v);
        g_rev[v].push_back(u);
    }
}

void dfs1(int u, int par) {
    for (int v : g[u]) {
        if (visited[v]) continue;
        visited[v] = true;
        dfs1(v, u);
    }
    nodes.push(u);
}

template <typename T>
void printArray(const vector<T> &arr) {
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]\n";
}

void dfs2(int u, int par) {
    for (int v : g_rev[u]) {
        if (visited[v]) continue;
        visited[v] = true;
        components[numOfComponents - 1].push_back(v);
        dfs2(v, u);
    }
}

void kosaraju(int n, int m) {
    visited.resize(n + 1, false);
    for (int i = 1; i < n; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        dfs1(i, -1);
    }

    visited.assign(n + 1, false);

    while (!nodes.empty()) {
        int node = nodes.top();
        nodes.pop();
        if (visited[node])
            continue;

        visited[node] = true;
        components.push_back({node});
        ++numOfComponents;
        dfs2(node, -1);
    }
    for (vector<int> comp : components) {
        for (int node : comp) {
            cout << node << " ";
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ipgraph(n, m);
    kosaraju(n, m);
    return 0;
}