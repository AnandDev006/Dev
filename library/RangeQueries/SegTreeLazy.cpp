/*
  author : Anand
*/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

// #define LOCAL

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int INF = 1e18 + 5;
const int MOD = 1000000007;


vector<int> tree;
vector<int> lazy;

int combine(int a, int b) { // TODO
    return a + b;
}

void push(int v) {  // TODO
    tree[2 * v] += lazy[v];
    lazy[2 * v] += lazy[v];
    tree[2 * v + 1] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
    lazy[v] = 0;
}


void buildTree(const vector<int> &a, int v, int tl, int tr) {
    if ( tl == tr) {
        tree[v] = a[tl];  // TODO
    } else {
        int tm = tl + (tr - tl) / 2;

        buildTree(a, v * 2, tl, tm);
        buildTree(a, v * 2 + 1, tm + 1 , tr);

        tree[v] = 0;  // TODO
    }
}

int getSegTreeData(int v, int tl, int tr, int ql, int qr) {
    if (ql > qr)
        return 0; // TODO

    if (ql <= tl && tr <= qr)
        return tree[v];

    push(v); // TODO

    int tm = tl + (tr - tl) / 2;

    int val = combine(getSegTreeData(v * 2, tl, tm, ql, min(qr, tm)),
                   getSegTreeData(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr)); // TODO
    return val;
}

void updateSegTreeData(int v, int tl, int tr, int ql, int qr, int add) {
    if ( ql > qr) return;

    if (ql == tl && qr == tr) {
        tree[v] += add;  // TODO
        lazy[v] += add;
    } else {
        push(v); // TODO

        int tm = tl + (tr - tl) / 2;

        updateSegTreeData(v * 2, tl, tm, ql, min(qr, tm), add);
        updateSegTreeData(v * 2  + 1, tm + 1, tr, max(ql, tm + 1), qr, add);

        tree[v] = combine( tree[2 * v], tree[2 * v + 1]); // TODO
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> inputArr({5, 8, 6, 3, 2, 7, 2, 6, 9});
    int n = inputArr.size();

    tree = vector<int>(4 * n, 0); // TODO
    lazy = vector<int>(4 * n, 0); // TODO

    buildTree(inputArr, 1, 0, n - 1);


    return 0;
}