#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long
#define dbg(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
}

vector<pair<bitset<7>, int>> valid({{bitset<7>("1111011"), 9}, {bitset<7>("1111111"), 8}, {bitset<7>("1010010"), 7}, {bitset<7>("1101111"), 6}, {bitset<7>("1101011"), 5}, {bitset<7>("0111010"), 4}, {bitset<7>("1011011"), 3}, {bitset<7>("1011101"), 2}, {bitset<7>("0010010"), 1}, {bitset<7>("1110111"), 0} });
unordered_map<string, int> allowed = {{"1111011", 9}, {"1111111", 8}, {"1010010", 7}, {"1101111", 6}, {"1101011", 5}, {"0111010", 4}, {"1011011", 3}, {"1011101", 2}, {"0010010", 1}, {"1110111", 0} };
vector<bitset<7>> a(2005);

void backTrack(vector <vector<pair<int, int>>> &vals, int i, vector<int> &pos, int &k) {
    if( k == 0) {
        
    }

    if( i == (int)vals.size()) {

    }

    int m = vals[i].size();
    for ( int  j = 0 ; j < m ; j++) {
        if (vals[i][j].first <= k) {
            k -= vals[i][j].first;
            pos[i] = j;
            backTrack( vals, i+1, pos, k);
        }
    }

}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    for ( int i = 0 ; i < n ; ++i) {
        cin >> s;
        a[i] = bitset<7>(s);
    }
    vector <vector<pair<int, int>>> vals(n, vector<pair<int, int>>(0) );
    for (int i = 0 ; i < n ; ++i) {
        auto x = a[i];
        for ( int j = 0 ; j < 9 ; ++j) {
            auto y = valid[j].first;
            auto res = x | y;
            if ( allowed.find(res.to_string()) != allowed.end() && (int)(res ^ x).count() < k ) {
                vals[i].push_back( {(res ^ x).count(), allowed[res.to_string()]} );
            }
        }
    }
}

signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}