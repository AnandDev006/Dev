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



class SegTree2D {
    vector<vector<int>> t;
    int n, m;
    int combine(int a, int b) {
        return a + b;
    }
public:
    SegTree2D(const vector<vector<int>> &inputArr) {
        n = inputArr.size();
        m = inputArr[0].size();
        t = vector<vector<int>>(4 * n, vector<int>(4 * m));
        build_x(inputArr, 1, 0, n - 1);
    }

    void build_y(const vector<vector<int>> &a, int vx, int lx, int rx, int vy, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx)
                t[vx][vy] = a[lx][ly];
            else
                t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
        } else {
            int my = ly + (ry - ly) / 2;

            build_y(a, vx, lx, rx, vy * 2, ly, my);
            build_y(a, vx, lx, rx, vy * 2 + 1, my + 1, ry);

            t[vx][vy] = t[vx][vy * 2] + t[vx][vy * 2 + 1];
        }
    }

    void build_x(const vector<vector<int>> &a, int vx, int lx, int rx) {
        if (lx != rx) {
            int mx = lx + (rx - lx) / 2;

            build_x(a, vx * 2, lx, mx);
            build_x(a, vx * 2 + 1, mx + 1, rx);
        }
        build_y(a, vx, lx, rx, 1, 0, m - 1);
    }

    int get_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry) return 0;
        if (ly == tly && try_ == ry) return t[vx][vy];

        int tmy = tly + (try_ - tly) / 2;
        return combine(get_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy))
                       , get_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
    }

    int get_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (lx > rx) return 0;
        if (lx == tlx && trx == rx) return get_y(vx, 1, 0, m - 1, ly, ry);
        int tmx = tlx + (trx - tlx) / 2;
        return combine( get_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry)
                        , get_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
    }

    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
        if (ly == ry) {
            if (lx == rx)
                t[vx][vy] = new_val;
            else
                t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
        } else {
            int my = ly + (ry - ly) / 2;
            if (y <= my)
                update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
            else
                update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
            t[vx][vy] = t[vx][vy * 2] + t[vx][vy * 2 + 1];
        }
    }

    void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
        if (lx != rx) {
            int mx = lx + (rx - lx) / 2;
            if (x <= mx)
                update_x(vx * 2, lx, mx, x, y, new_val);
            else
                update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
        }
        update_y(vx, lx, rx, 1, 0, m - 1, x, y, new_val);
    }
};

signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);



    return 0;
}