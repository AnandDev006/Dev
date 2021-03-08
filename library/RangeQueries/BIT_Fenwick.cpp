struct FenwickTree {
  vector<int> tree;
  int n;

  FenwickTree() : n(0) {}
  FenwickTree(int _n) : n(_n), tree(_n) {}
  FenwickTree(const vector<int>& arr) {
    n = arr.size();
    tree.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      add(i, arr[i]);
    }
  }

  void add(int p, int val) {
    assert(0 <= p && p < n);
    ++p;

    while (p <= n) {
      tree[p - 1] += val;
      p += p & -p;
    }
  }

  int sum(int r) {
    ++r;
    int sum = 0;
    while (r > 0) {
      sum += tree[r - 1];
      r -= r & -r;
    }
    return sum;
  }

  int sum(int l, int r) {
    assert(0 <= l && l <= r && r < n);
    return sum(r) - sum(l - 1);
  }
};