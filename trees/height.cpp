#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *left, *right;
  Node() : value(0), left(nullptr), right(nullptr) {}
  Node(int x) : value(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *l, Node *r) : value(x), left(l), right(r) {}
};

int height(struct Node *node) {
  if (node == nullptr) {
    return 0;
  }

  return 1 + max(height(node->left), height(node->right));
}

int main() { return 0; }
