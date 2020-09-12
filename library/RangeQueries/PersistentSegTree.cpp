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

struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *a, Vertex *b) : l(a), r(b), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};


Vertex * root;

int combine(int a, int b) {
    return a + b;
}

Vertex* build(vector<int> a, int tl, int tr) {
    if (tl == tr) return new Vertex(a[tl]);

    int tm = (tl + tr) / 2;

    return new Vertex(build(a, tl, tm), build(a, tm + 1, tr));
}

int get_sum(Vertex* v, int tl, int tr, int ql, int qr) {
    if (ql > qr) return 0;

    if (ql == tl && tr == qr) return v->sum;

    int tm = tl + (tr - tl) / 2;

    return combine(get_sum(v->l, tl, tm, ql, min(qr, tm))
                   , get_sum(v->r, tm + 1, tr, max(ql, tm + 1), qr));
}

Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new Vertex(new_val);

    int tm = tl + (tr - tl) / 2;

    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm + 1, tr, pos, new_val));
}


signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    vector<int> inputArr({1, 2, 3, 4, 5, 6});
    root = build(inputArr, 0, inputArr.size() - 1 );

    return 0;
}