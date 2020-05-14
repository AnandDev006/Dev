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
const int N = 3e5, M = N;

class Node {
   public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        left = right = NULL;
        this->data = data;
    }
};

void preOrderRec(Node* node) {
    cout << node->data << ' ';
    if (node->left) preOrderRec(node->left);
    if (node->right) preOrderRec(node->right);
}

void inOrderRec(Node* node) {
    if (node->left) inOrderRec(node->left);
    cout << node->data << ' ';
    if (node->right) inOrderRec(node->right);
}

void postOrderRec(Node* node) {
    if (node->left) postOrderRec(node->left);
    if (node->right) postOrderRec(node->right);
    cout << node->data << ' ';
}

void preOrderIter(Node* node) {
    stack<Node*> s;
    s.push(node);
    while (!s.empty()) {
        Node* temp = s.top();
        s.pop();
        cout << temp->data << ' ';
        if (temp->right) s.push(temp->right);
        if (temp->left) s.push(temp->left);
    }
}

void inOrderIter(Node* node) {
    stack<Node*> s;
    Node* cur = node;
    while (cur || !s.empty()) {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        cout << cur->data << ' ';
        cur = cur->right;
    }
}

void postOrderIter(Node* node) {
    stack<Node*> s1, s2;
    s1.push(node);
    while (!s1.empty()) {
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left) s1.push(temp->left);
        if (temp->right) s1.push(temp->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << ' ';
        s2.pop();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preOrderRec(root);
    cout << '\n';
    inOrderRec(root);
    cout << '\n';
    postOrderRec(root);
    cout << '\n';
    preOrderIter(root);
    cout << '\n';
    inOrderIter(root);
    cout << '\n';
    postOrderIter(root);
    cout << '\n';

    return 0;
}