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
unordered_map<int, int> nodeWeight;
unordered_map<int, pair<int, int>> table;
int DP[N];

void ipgraph(int n, int m) {
    int i, u, v, w;
    while (m--) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    while (n--) {
        cin >> u >> w;
        nodeWeight[u] = w;
    }
}

void dfs(int u, int par, vector<int> &inputArr) {
    inputArr.push_back(nodeWeight[u]);
    table[u] = {(int)(inputArr.size()) - 1, 1};
    for (int v : g[u]) {
        if (v == par) continue;
        dfs(v, u, inputArr);
        table[u].second += table[v].second;
    }
}

template <typename T>
class SegmentTree {
    vector<T> tree;
    int treeLen;

   public:
    SegmentTree(const vector<T> &inputArr) {
        int inputArrLen = sz(inputArr);
        this->treeLen = 2 * pow(2, int(ceil(log2(inputArrLen)))) - 1;

        this->tree = vector<T>(this->treeLen, 0);  // initialise as per merge operation

        for (int i = inputArrLen - 1; i >= 0; --i) {
            this->tree[this->treeLen / 2 + i] = inputArr[i];
        }

        for (int i = (this->treeLen / 2) - 1; i >= 0; --i) {
            // create tree nodes based on tree type ( sum, min, max ....)
            this->tree[i] = this->tree[2 * i + 1] + this->tree[2 * i + 2];
        }
    }
    T getSegTreeData(int a, int b) {
        a += this->treeLen / 2;
        b += this->treeLen / 2;
        if (a >= this->treeLen || b < 0) return 0;
        if (a < 0) a = 0;
        if (b >= this->treeLen) b = this->treeLen - 1;

        // initialise based on tree type ( sum, min, max ....)
        T result = 0;
        while (a <= b) {
            // if right node on left pointer, take value and move right
            if (a % 2 == 0) result += this->tree[a++];

            // if left node on right pointer, take value and move left
            if (b % 2 == 1) result += this->tree[b--];

            // go to parent
            a = (a - 1) / 2;
            b = (b - 1) / 2;
        }
        return result;
    }
    void updateSegTreeData(T val, int pos) {
        pos += this->treeLen / 2;
        if (pos < 0 || pos >= this->treeLen) return;

        this->tree[pos] += val;
        for (int i = pos / 2; i >= 1; i /= 2) {
            // update logic based on tree type ( sum, min, max ....)
            this->tree[i] = this->tree[2 * i + 1] + this->tree[2 * i + 2];
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ipgraph(n, m);
    vector<int> inputArr;
    dfs(1, -1, inputArr);
    SegmentTree<int> tree(inputArr);
    cout << tree.getSegTreeData(table[2].first, table[2].first + table[2].second - 1) << '\n';

    return 0;
}