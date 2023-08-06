#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *left, *right;
  Node() : left(nullptr), right(nullptr), value(0) {}
  Node(int v) : left(nullptr), right(nullptr), value(v) {}
  Node(Node *l, Node *r, int v) : left(l), right(r), value(v) {}
};

vector<vector<int>> threeInOne(Node *root) {
  if (root == nullptr) {
    return {};
  }
  vector<int> pre, in, post;
  stack<pair<Node *, int>> st;

  st.push({root, 1});

  while (!st.empty()) {
    Node *node = st.top().first;
    int num = st.top().second;

    st.pop();

    if (num == 1) {
      pre.push_back(node->value);
      num++;
      st.push({node, num});
      if (node->left != nullptr) {
        st.push({node->left, 1});
      }
    }
    if (num == 2) {
      in.push_back(node->value);
      num++;
      st.push({node, num});
      if (node->right != nullptr) {
        st.push({node->right, 1});
      }
    }
    if (num == 3) {
      post.push_back(node->value);
    }
  }

  vector<vector<int>> res = {pre, in, post};
  return res;
}

int main() { return 0; }