#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *left, *right;
  Node() : value(0), left(nullptr), right(nullptr) {}
  Node(int x) : value(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *l, Node *r) : value(x), left(l), right(r) {}
};

vector<vector<int>> verticalOrder(Node *root) {
  map<int, map<int, multiset<int>>> nodes;
  queue<pair<Node *, pair<int, int>>> q;
  q.push({root, {0, 0}});
  while (!q.empty()) {
    Node *node = q.front().first;
    int ver = q.front().second.first, level = q.front().second.second;
    q.pop();
    nodes[ver][level].insert(node->value);
    if (node->left) {
      q.push({node->left, {ver - 1, level + 1}});
    }
    if (node->right) {
      q.push({node->right, {ver + 1, level + 1}});
    }
  }

  vector<vector<int>> ans;
  for (auto p : nodes) {
    vector<int> col;
    for (auto q : p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }

  return ans;
}

int main() { return 0; }