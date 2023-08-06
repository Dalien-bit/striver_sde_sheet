#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *left, *right;
  Node() : value(0), left(nullptr), right(nullptr) {}
  Node(int x) : value(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *l, Node *r) : value(x), left(l), right(r) {}
};

vector<vector<int>> levelOrder(Node *root) {
  if (root == nullptr) {
    return {};
  }
  vector<vector<int>> ans;
  queue<Node *> q;
  q.push(root);
  while (q.empty() == false) {
    int qsize = q.size();
    vector<int> level;
    for (int i = 0; i < qsize; i++) {
      Node *curr = q.front();
      q.pop();
      level.push_back(curr->value);

      if (curr->left) {
        q.push(curr->left);
      }
      if (curr->right) {
        q.push(curr->right);
      }
    }

    ans.push_back(level);
  }

  return ans;
}

int main() { return 0; }