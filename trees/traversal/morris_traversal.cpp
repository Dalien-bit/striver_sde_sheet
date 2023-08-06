#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node *left, *right;
  Node() : left(nullptr), right(nullptr), value(0) {}
  Node(int v) : left(nullptr), right(nullptr), value(v) {}
  Node(Node *l, Node *r, int v) : left(l), right(r), value(v) {}
};



vector<int> morrisInorder(Node *root) {
  vector<int> &inorder;
  Node *curr = root;
  while (curr != nullptr) {
    if (curr->left == nullptr) {
      inorder.push_back(curr->value);
      curr = curr->right;
    } else {
      TreeNode *prev = root->left;
      while (prev != nullptr and prev->right != curr) {
        prev = prev->right;
      }
      if (prev->right == nullptr) {
        prev->right = curr;
        curr = curr->left;
      } else {
        prev->right = nullptr;
        inorder.push_back(curr->value);
        curr = curr->right;
      }
    }
  }

  return inorder;
}

vector<int> morrisPreorder(Node *root) {
  vector<int> &preorder;
  Node *curr = root;
  while (curr != nullptr) {
    if (curr->left == nullptr) {
      inorder.push_back(curr->val);
      curr = curr->right;
    } else {
      TreeNode *prev = root->left;
      while (prev != nullptr and prev->right != curr) {
        prev = prev->right;
      }
      if (prev->right == nullptr) {
        prev->right = curr;
        inorder.push_back(curr->value);
        curr = curr->left;
      } else {
        prev->right = nullptr;
        curr = curr->right;
      }
    }
  }

  return inorder;
}

int main() { return 0; }