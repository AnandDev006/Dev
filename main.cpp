/*
    author : Anand
    Return the root node of a binary search tree that matches the given preorder traversal.

    (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

    

    Example 1:

    Input: [8,5,1,7,10,12]
    Output: [8,5,10,1,7,null,12] -> BFS output

*/

#include <bits/stdc++.h>

// #include <math.h>

// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <utility>
// #include <vector>

#define sz(a) int((a).size())
#define ll long long
#define pb push_back
#define mp(a, b) make_pair(ll(a), ll(b))
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define PI 3.1415926535897932384626

using namespace std;

const int INF = 1e9 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int pos;
    int n;
    int INF = 1e9 + 5;
    TreeNode* makeBST(vector<int>& preorder, int low, int high) {
        if (this->pos == this->n || !(preorder[this->pos] > low && preorder[this->pos] < high))
            return NULL;
        int value = preorder[this->pos];
        TreeNode* node = new TreeNode(value);
        this->pos++;
        node->left = makeBST(preorder, low, value);
        node->right = makeBST(preorder, value, high);
        return node;
    }

   public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int low = -INF, high = INF;
        this->pos = 0;
        this->n = preorder.size();
        return makeBST(preorder, low, high);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}