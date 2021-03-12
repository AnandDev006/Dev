struct DisjointSet {
    vector<long long> parent;
    vector<long long > rnk;

    DisjointSet(long long n) : parent(n), rnk(n) {
        for (long long i = 0 ; i < n ; ++i)
            makeSet(i);
    }

    void makeSet(long long v) {
        parent[v] = v;
        rnk[v] = 0;
    }

    long long findSet(long long v) {
        if (v == parent[v]) return v;
        return parent[v] = findSet(parent[v]);
    }

    bool unionSet(long long x, long long y) {
        x = findSet(x);
        y = findSet(y);

        if (x == y) return false;

        if (rnk[x] < rnk[y])
            swap(x, y);
        parent[y] = x;
        if (rnk[x] == rnk[y])
            ++rnk[x];

        return true;
    }
};