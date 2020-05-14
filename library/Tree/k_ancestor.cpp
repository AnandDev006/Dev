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
const int N = 10, M = N;

vector<int> g[N];
vector<vector<int>> ancestor(N, vector<int>(N, 0));
int DP[N];

void ipgraph(int n, int m) {
    int i, u, v;
    while (m--) {
        cin >> u >> v;
        ancestor[v][0] = u;
        g[u].push_back(v);
    }
}

void precalcAncestors(int n, int m) {
    for (int i = 1; i < (int)log2(n) + 1; ++i) {
        for (int node = 1; node <= n; ++node) {
            ancestor[node][i] = ancestor[ancestor[node][i - 1]][i - 1];
        }
    }
}

int getAncestor(int node, int level) {
    while (level > 0) {
        node = ancestor[node][(int)log2(level)];
        level -= (int)pow(2, (int)log2(level));
    }
    return node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ipgraph(n, m);

    precalcAncestors(n, m);

    cout << getAncestor(6, 2) << '\n';

    return 0;
}