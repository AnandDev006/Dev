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
const int MAXN = 1e3 + 5;
int K = 25;
int N;

vector<vector<int>> st(MAXN, vector<int>(K + 1, 0));
vector<int> LOG(MAXN + 1);

void precomputeRSQ(const vector<int> &array) {
    for (int i = 0; i < N; i++)
        st[i][0] = array[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
}

ll getRSQ(int L, int R) {
    long long sum = 0;
    for (int j = K; j >= 0; j--) {
        if ((1 << j) <= R - L + 1) {
            sum += st[L][j];
            L += 1 << j;
        }
    }
    return sum;
}

void preComputeRMQ(const vector<int> &array) {
    LOG[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        LOG[i] = LOG[i / 2] + 1;

    for (int i = 0; i < N; i++)
        st[i][0] = array[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

}

ll getRMQ(int L, int R) {
    int j = LOG[R - L + 1];
    int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
    return minimum;
}


signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    vector<int> inp({1, 2, 3, 4, 5, 6, 7, 8, 9});
    N = inp.size();
    K = log2(N) + 1;

    // precomputeRSQ(inp);
    preComputeRMQ(inp);
    cout << getRMQ(2, 6) << endl;

    return 0;
}