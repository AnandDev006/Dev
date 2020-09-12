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

vector<int> tree;

int combine(int a, int b) { // TODO
    return a + b;
}

void buildTree(const vector<int> &a, int v, int tl, int tr) {
    if ( tl == tr) {
        tree[v] = a[tl];  // TODO
    } else {
        int tm = tl + (tr - tl) / 2;

        buildTree(a, v * 2, tl, tm);
        buildTree(a, v * 2 + 1, tm + 1 , tr);

        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);  // TODO
    }
}

int getSegTreeData(int v, int tl , int tr, int ql, int qr) {
    if (tl > qr || tr < ql || ql > qr) return 0;  // TODO

    if (ql == tl && qr == tr) {
        return tree[v];
    }

    int tm = tl + (tr - tl) / 2;

    int val = combine(getSegTreeData(v * 2, tl, tm, ql, min(qr, tm)),
                   getSegTreeData(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr));  // TODO
    return val;
}

void updateSegTreeData(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = new_val;  // TODO
    } else {

        int tm = tl + (tr - tl) / 2;

        if (pos <= tm)
            updateSegTreeData(v * 2, tl, tm, pos, new_val);
        else
            updateSegTreeData(v * 2 + 1, tm + 1, tr, pos, new_val);

        tree[v] = combine(tree[v * 2] , tree[v * 2 + 1]);  // TODO
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> inputArr({5, 8, 6, 3, 2, 7, 2, 6, 9});
    int n = inputArr.size();

    tree = vector<int>(4 * n, 0); // TODO

    buildTree(inputArr, 1, 0, n - 1);


    cout << getSegTreeData(1, 0, inputArr.size() - 1, 7, 8) << '\n';
    updateSegTreeData(1, 0, inputArr.size() - 1, 7, 0);
    cout << getSegTreeData(1, 0, inputArr.size() - 1, 7, 8) << '\n';
    
    return 0;
}