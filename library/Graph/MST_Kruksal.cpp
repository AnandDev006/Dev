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
    return to_string((string)s);
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
    for (const auto& x : v) {
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
    return "(" + to_string(p.firstirst) + ", " + to_string(p.secondecond) + ")";
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

    return 0;
}