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

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "\t[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int INF = 1e18 + 5;
const int MOD = 1000000007;

//////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    /*

    1 2 3 4 5 6
    1 6 3 2 5 4
    1 6 4 2 3 5
    4 1 6 2 3 5

    2 4 5 1 6 3

    4 1 6 2 3 5
    1 2 6 4 3 5
    1 2 3 4 5 6


    */

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1), p(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            p[a[i]] = i;
        }
        int c = 0;
        debug(a, p, c);
        vector<vector<int>> ans;
        for (int i = 1; i <= n - 2; ++i) {
            if (a[i] == i) continue;
            int v1 = i, v3 = p[v1], v2 = p[v3];
            ans.push_back({v1, v2, v3});
            int temp = a[v3];
            a[v3] = a[v2];
            a[v2] = a[v1];
            a[v1] = temp;
            p[a[v1]] = v1;
            p[a[v2]] = v2;
            p[a[v3]] = v3;
            c++;
            debug(a, p, c);
            if (c > k) break;
        }

        if (c > k || a[n] != n || a[n - 1] != n - 1)
            cout << "-1\n";
        else {
            cout << c << "\n";
            for (auto& v : ans) {
                cout << v[0] << " " << v[1] << " " << v[2] << '\n';
            }
        }
    }

    return 0;
}