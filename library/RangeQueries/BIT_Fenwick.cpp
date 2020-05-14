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