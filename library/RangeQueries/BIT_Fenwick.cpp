struct FenwickTree {

  vector<long long> bit;
  long long n;

  FenwickTree(long long _n) : n(_n + 1), bit(_n + 1) {}
  FenwickTree(const vector<long long> arr) : FenwickTree(arr.size()) {
    for (long long i = 0 ; i < n - 1 ; ++i) {
      add(arr[i], i);
    }
  }

  void add(long long val, long long idx) {
    assert(0 <= idx && idx < n - 1);
    for (++idx ; idx < n ; idx += (idx & -idx)) {
      bit[idx] += val;
    }
  }

  long long sum(long long idx) {
    assert(0 <= idx && idx < n - 1);
    long long ans = 0;
    for (++idx ; idx > 0 ; idx -= (idx & -idx) ) {
      ans += bit[idx];
    }
    return ans;
  }

  long long sum(long long L, long long R) {
    return sum(R) - sum(L - 1);
  }
};