#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *left, *right;
  Node() : left(nullptr), right(nullptr), value(0) {}
  Node(int v) : left(nullptr), right(nullptr), value(v) {}
  Node(Node *l, Node *r, int v) : left(l), right(r), value(v) {}
};

void rightView(Node *node, int level, vector<int> &view) {
  if (node == nullptr) {
    return;
  }

  if (level == view.size()) {
    view.push_back(node->value);
  }

  rightView(node->right, level + 1, view);
  rightView(node->left, level + 1, view);
}

void leftView(Node *node, int level, vector<int> &view) {
  if (node == nullptr) {
    return;
  }

  if (level == view.size()) {
    view.push_back(node->value);
  }

  leftView(node->left, level + 1, view);
  leftView(node->right, level + 1, view);
}

void getView(Node *root) {
  vector<int> left_view, right_view;
  lefttView(root, 0, left_view);
  rightView(root, 0, right_view);
}

int main() { return 0; }