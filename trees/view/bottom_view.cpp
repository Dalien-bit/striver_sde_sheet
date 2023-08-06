#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *left, *right;
  Node() : left(nullptr), right(nullptr), value(0) {}
  Node(int v) : left(nullptr), right(nullptr), value(v) {}
  Node(Node *l, Node *r, int v) : left(l), right(r), value(v) {}
};

vector<int> bottomView(Node *root) {
  if (root == nullptr) {
    return {};
  }
  queue<pair<Node *, int>> q;
  map<int, int> hash;

  q.push({root, 0});

  while (!q.empty()) {
    Node *curr = q.front().first;
    int line = q.front().second;
    q.pop();

    hash[line] = curr->value;
    if (curr->left != nullptr) {
      q.push({curr->left, line - 1});
    }
    if (curr->right != nullptr) {
      q.push({curr->right, line + 1});
    }
  }

  vector<int> view;
  for (auto it : hash) {
    view.push_back(it.second);
  }
  return view;
}

int main() { return 0; }