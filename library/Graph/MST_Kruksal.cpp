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

vector<pair<int, pair<int, int>>> g;    // edgeList
vector<pair<int, pair<int, int>>> MST;  // edgeList

vector<int> parent;
vector<int> rnk;

void makeSet(int v) {
    parent[v] = v;
    rnk[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return (parent[v] = find_set(parent[v]));
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
    return false;
}

void kruksal(int m) {
    sort(g.begin(), g.begin() + m, [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) { return a.first < b.first; });
    for (auto e : g) {
        int a = e.second.first;
        int b = e.second.second;
        int w = e.first;
        if (union_sets(a, b)) {
            MST.push_back({w, {a, b}});
        }
    }
}

void initUnionFindSet(int n) {
    parent = vector<int>(n);
    rnk = vector<int>(n);
    for (int i = 1; i <= n; ++i) {
        makeSet(i);
    }
}

void ipgraph(int n, int m) {
    int i, u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        g.push_back({w, {u, v}});
    }
}

signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    ipgraph(n, m);
    initUnionFindSet(n);
    kruksal(m);
    for (auto e : MST) {
        int a = e.second.first;
        int b = e.second.second;
        int w = e.first;
        printf("%d-%d : %d\n", a, b, w);
    }
    return 0;

}