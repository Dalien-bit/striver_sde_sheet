#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *left, *right;
  Node() : left(nullptr), right(nullptr), value(0) {}
  Node(int v) : left(nullptr), right(nullptr), value(v) {}
  Node(Node *l, Node *r, int v) : left(l), right(r), value(v) {}
};

void inorder(Node *node, vector<int> &arr) {
  if (node == nullptr) {
    return;
  }

  arr.push_back(node->value);
  inorder(node->left, arr);
  inorder(node->right, arr);
}

int main() { return 0; }