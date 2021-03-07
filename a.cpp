/*
  author : Anand
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const int N = 1e7;
const int K = 25;

void solve(int tc = 1) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0), b(n, 0), pref1(n+1, 0), pref2(n+1, 0);
  for(int i = 0 ; i < n ; ++i) 
    cin >> a[i];
  for(int i = 0 ; i < n ; ++i)
    cin >> b[i];
  for(int i = 1 ; i <=n ; ++i) {
    pref1[i] = pref1[i-1] + (b[i-1] * a[i-1]);
    pref2[i] = pref2[i-1] + a[i-1];
  }
  int ans = 0;
  for(int i = k ; i <= n ; ++i) {
    // int lec =   [0,i-k] [i-k,i] [i, n]
    int lec = pref1[i-k] + (pref2[i] - pref2[i-k]) + (pref1[n] - pref1[i]);
    ans = max(ans, lec);
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; ++t) solve(t);

  return 0;
}