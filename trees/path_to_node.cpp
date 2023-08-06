#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *left, *right;
  Node() : value(0), left(nullptr), right(nullptr) {}
  Node(int x) : value(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *l, Node *r) : value(x), left(l), right(r) {}
};

bool pathUtil(Node *node, int dest, vector<int> &st) {
  if (node == nullptr) {
    return false;
  }

  st.push_back(node->value);
  if (node->value == dest) {
    return true;
  }

  if (pathUtil(node->left, dest, st) or pathUtil(node->right, dest, st)) {
    return true;
  }

  st.pop_back();
  return false;
}

vector<int> getPath(Node *root, int dest) {
  vector<int> v;

  if (pathUtil(root, dest, v)) {
    return {-1};
  }

  return v;
}

int main() { return 0; }