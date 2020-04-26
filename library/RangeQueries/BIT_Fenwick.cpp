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

template <typename T>
class BIT {
    vector<T> tree;
    int p(int k) { return (k & (-k)); };

   public:
    BIT(const vector<T>& arr) {
        int arrLen = sz(arr);
        tree = vector<T>(arrLen + 1, 0);
        for (int i = 0; i < arrLen; ++i) {
            updateBIT(arr[i], i);
        }
    }

    void updateBIT(int val, int idx) {
        ++idx;
        if (idx >= sz(tree)) return;

        while (idx <= sz(tree)) {
            (tree)[idx] += val;
            idx += p(idx);
        }
    }

    void updateBIT(int l, int r, int val) {
        updateBIT(l, val);
        updateBIT(r + 1, -val);
    }

    T getBITSum(int idx) {
        ++idx;
        if (idx >= sz(tree)) idx = sz(tree) - 1;

        T sum = 0;
        while (idx > 0) {
            sum += (tree)[idx];
            idx -= p(idx);
        }
        return sum;
    }

    T getBITSum(int l, int r) {
        return getBITSum(r) - getBITSum(l - 1);
    }
};

signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    return 0;
}