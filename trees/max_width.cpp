#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *left, *right;
  Node() : value(0), left(nullptr), right(nullptr) {}
  Node(int x) : value(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *l, Node *r) : value(x), left(l), right(r) {}
};

int maxWidth(Node *root) {
  if (!root) {
    return 0;
  }
  int ans = 0;
  queue<pair<Node *, int>> q;
  q.push({root, 0});
  while (!q.empty()) {
    int size = q.size(), cmin = q.front().second, l, r;

    for (int i = 0; i < size; i++) {
      int id = q.front().second - cmin;
      Node *temp = q.front().first;
      q.pop();
      if (i == 0) {
        l = id;
      }
      if (i == size - 1) {
        r = id;
      }
      if (temp->left) {
        q.push({temp->left, id * 2 + 1});
      }
      if (temp->right) {
        q.push({temp->right, id * 2 + 2});
      }
    }

    ans = max(ans, r - l + 1);
  }

  return ans;
}

int main() { return 0; }