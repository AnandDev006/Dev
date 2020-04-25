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

signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    set<int>  d;
    for ( int i = 0 ; i < m ; ++i) {
        int x;
        cin >> x;
        d.insert(x);
    }

    int g, r;
    cin >> g >> r;

    int pos = 0;
    int time = 0;
    while ( pos < n) {
        int t = 0;
        auto newP = d.lower_bound(pos + g);

        if (newP == d.end() || *newP == n ) {
            if(newP == d.end()) {
                newP--;
            }
            time += (*newP - pos);
            cout << time << "\n";
            return 0;
        }
        if ( *newP > (pos + g)) {
            if (*newP == 0) {
                cout << "-1\n";
                return 0;
            }
            newP--;
        }

        t += (*newP - pos );
        pos = *newP;

        while ( t != g ) {
            newP--;
            t += (pos - *newP);
            pos = *newP;
            if ( t > g || (t != g && pos == 0)) {
                cout << "-1\n";
                return 0;
            }
        }

        if (pos == 0) {
            cout << "-1\n";
            return 0;
        }

        time += (t + r);
    }

    return 0;
}