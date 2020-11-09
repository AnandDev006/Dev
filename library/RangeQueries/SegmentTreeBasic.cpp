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

// 0 indexed
struct SegTree {
    vector<int> tree;
    int combine(int left, int right) {
        return left + right;
    }

    SegTree(const vector<int> &v) {
        n = v.size();
        tree.assign(4 * n, 0);
        buildTree(v, 1, 0, n - 1);
    }

    void buildTree(const vector<int> &v, int node, int tL, int tR) {
        if (tL == tR)
            tree[node] = v[tL];
        else {
            int tM = tL + (tR - tL) / 2;
            buildTree(v, node * 2, tL, tM);
            buildTree(v, node * 2 + 1, tM + 1, tR);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int getVal(int node, int tL, int tR, int qL, int qR) {
        if (qL > qR) return 0;
        if (tL == qL && tR == qR) return tree[node];
        int tM = tL + (tR - tL) / 2;
        int val = combine(getVal(node * 2, tL, tM, qL, min(qR, tM)), getVal(node * 2 + 1, tM + 1, tR, max(qL, tM + 1), qR));
        return val;
    }

    void updateVal(int node, int tL, int tR, int pos, int newVal) {
        if (tL == tR)
            tree[node] = newVal;
        else {
            int tM = tL + (tR - tL) / 2;
            if (pos <= tM)
                updateVal(node * 2, tL, tM, pos, newVal);
            else
                updateVal(node * 2 + 1, tM + 1, tR, pos, newVal);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }
};

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