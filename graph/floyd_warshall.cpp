#include <bits/stdc++.h>
using namespace std;

class Solution {
  const int INF = 1e6;

public:
  void shortest_distance(vector<vector<int>> &matrix) {
    const int n = matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == -1) {
          matrix[i][j] = INF;
        }
      }
      matrix[i][i] = 0;
    }
    for (int via = 0; via < n; via++) {
      for (int i = 0; i < n; i++) {
        if (via == i) {
          continue;
        }
        for (int j = 0; j < n; j++) {
          if (via == j) {
            continue;
          }
          matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
        }
      }
    }
    for (auto &r : matrix) {
      for (auto &wt : r) {
        wt = (wt == INF) ? -1 : wt;
      }
    }
  }
};

int main() { return 0; }