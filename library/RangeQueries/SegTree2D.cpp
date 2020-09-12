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

vector<vector<int>> t;
int n, m;

int combine(int a, int b) { // TODO
    return a + b;
}

void build_y(const vector<vector<int>> &a, int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = a[lx][ly]; // TODO
        else
            t[vx][vy] = combine(t[vx * 2][vy] , t[vx * 2 + 1][vy]);  // TODO
    } else {
        int my = ly + (ry - ly) / 2;

        build_y(a, vx, lx, rx, vy * 2, ly, my);
        build_y(a, vx, lx, rx, vy * 2 + 1, my + 1, ry);

        t[vx][vy] = combine( t[vx][vy * 2] , t[vx][vy * 2 + 1] ); // TODO
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

    // TODO
    int val = combine(get_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy))
                      , get_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
    return val;
}

int get_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx) return 0;
    if (lx == tlx && trx == rx) return get_y(vx, 1, 0, m - 1, ly, ry);

    int tmx = tlx + (trx - tlx) / 2;

    // TODO
    int val = combine( get_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry)
                       , get_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
    return val;
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = new_val; // TODO
        else
            t[vx][vy] = combine(t[vx * 2][vy] , t[vx * 2 + 1][vy]); // TODO
    } else {
        int my = ly + (ry - ly) / 2;

        if (y <= my)
            update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);

        // TODO
        t[vx][vy] = combine(t[vx][vy * 2] , t[vx][vy * 2 + 1]);
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


signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    vector<vector<int>> inputArr;

    n = inputArr.size();
    m = inputArr[0].size();

    t = vector<vector<int>>(4 * n, vector<int>(4 * m)); // TODO

    build_x(inputArr, 1, 0, n - 1);

    return 0;
}