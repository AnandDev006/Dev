#include <bits/stdc++.h>
#define ll long long int
#define fr(i, n) for (ll i = 0; i < n; i++)
#define fre(i, n) for (ll i = 1; i <= n; i++)
#define pb push_back
#define mp(i, j) make_pair(i, j)
#define fi first
#define se second
#define pii pair<ll, ll>
#define ve vector
#define piii pair<pii, ll>
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
using namespace std;

int main() {
    FAST;
#ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    string ans;
    ll t, n, k;
    cin >> t;

    while (t--) {
        cin >> k >> ans;
        n = ans.length();

        if (n == 1) {
            if (ans == "?") ans = "0";
            cout << ans << endl;
            continue;
        }

        if (k == 1) {
            if (ans == "0" || ans == "?")
                cout << "0\n";
            else
                cout << "NO\n";
            continue;
        }

        if (k == 2) {
            if (n % 2 == 1)
                cout << "NO\n";
            else {
                string tmp1 = "";
                string tmp2 = "";
                for (int i = 0; i < n; i++) {
                    tmp1 += i % 2 + '0';
                    tmp2 += (i + 1) % 2 + '0';
                }

                bool t1 = true, t2 = true;

                for (int i = 0; i < n; i++) {
                    if (ans[i] == '?') continue;
                    if (ans[i] != tmp1[i]) t1 = false;
                    if (ans[i] != tmp2[i]) t2 = false;
                }

                if (t1 == true)
                    cout << tmp1 << endl;
                else if (t2 == true)
                    cout << tmp2 << endl;
                else
                    cout << "NO" << endl;
            }
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (ans[i] != '?') continue;
            int l = (ans[(i - 1 + n) % n] == '?') ? -1 : ans[(i - 1 + n) % n] - '0';
            int r = (ans[(i + 1) % n] == '?') ? -1 : ans[(i + 1) % n] - '0';

            for (int k = 0; k < 3; k++) {
                if (k != l && k != r) {
                    ans[i] = k + '0';
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int r = ans[(i + 1) % n] - '0';
            if ((ans[i] - '0' == r))
                ans = "NO";
        }
        cout << ans << endl;
    }
}
