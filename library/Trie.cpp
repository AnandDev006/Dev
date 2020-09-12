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
const int ALPHABET_SIZE = 26;

struct TrieNode {
    vector<TrieNode*> children;
    bool isEndOfWord;
    TrieNode() {
        children = vector<TrieNode*>(ALPHABET_SIZE);
    }
};

TrieNode* getNode(void) {
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode *root, string key) {
    TrieNode *cur = root;

    for (int i = 0; i < (int)key.length(); i++) {
        int index = key[i] - 'a';
        if (!cur->children[index])
            cur->children[index] = getNode();

        cur = cur->children[index];
    }

    // mark last node as leaf
    cur->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key) {
    struct TrieNode *cur = root;

    for (int i = 0; i < (int)key.length(); i++) {
        int index = key[i] - 'a';
        if (!cur->children[index])
            return false;

        cur = cur->children[index];
    }

    return (cur != NULL && cur->isEndOfWord);
}

signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);



    return 0;
}