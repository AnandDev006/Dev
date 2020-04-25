/*
  author : Anand
*/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long

#ifdef ONLINE_JUDGE
#define DEBUG1(format) {}
#define DEBUG(format, ...) {} //Intentionally blank
#else
#define DEBUG1(format) fprintf(stderr, format )
#define DEBUG(format, ...) fprintf(stderr, format, __VA_ARGS__)
#endif

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

signed main() {
  cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--) {
  	int n;
  	cin >> n;
  	cout << __builtin_popcount(n) - 1 << "\n";
  }

  return 0;
}