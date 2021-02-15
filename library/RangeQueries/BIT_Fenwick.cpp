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
const int N = 1e7;
const int K = 25;

vector<int> a(N);
vector<int> dp(N);
int n;

struct BIT {
    vector<int> tree;
    int treeLen;
    int p(int k) { return (k & (-k)); };

    BIT(const vector<int>& arr) {
        treeLen = arr.size();
        tree.assign(treeLen + 1, 0);
        for (int i = 0; i < treeLen; ++i) {
            updateBIT(arr[i], i);
        }
    }

    void updateBIT(int val, int idx) {
        ++idx;

        while (idx < treeLen) {
            tree[idx] += val;
            idx += p(idx);
        }
    }

    void updateBIT(int l, int r, int val) {
        updateBIT(l, val);
        updateBIT(r + 1, -val);
    }

    int getBITSum(int idx) {
        ++idx;

        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= p(idx);
        }
        return sum;
    }

    int getBITSum(int l, int r) {
        return getBITSum(r) - getBITSum(l - 1);
    }
};

void solve() {
  
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}