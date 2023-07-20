#include <bits/stdc++.h>
using namespace std;

class Solution {
  int m, n, dx[3] = {1, 0, -1}, dy[3] = {1, 0, -1};
  vector<vector<bool>> vis;
  void init(int m1, int n1) {
    m = m1, n = n1;
    vis.resize(m, vector<bool>(n, false));
  }
  bool isValid(int i, int j) { return (i >= 0 and i < m and j >= 0 and j < n); }

public:
  void dfs(vector<vector<char>> &grid, int i, int j) {
    vis[i][j] = true;

    for (int x = 0; x <= 2; x++) {
      for (int y = 0; y <= 2; y++) {
        if (isValid(i + dx[x], j + dy[y]) and !vis[i + dx[x]][j + dy[y]] and
            grid[i + dx[x]][j + dy[y]] == '1') {
          dfs(grid, i + dx[x], j + dy[y]);
        }
      }
    }
  }
  int numIslands(vector<vector<char>> &grid) {
    init(grid.size(), grid[0].size());
    int islands = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!vis[i][j] and grid[i][j] == '1') {
          islands++;
          dfs(grid, i, j);
        }
      }
    }

    return islands;
  }
};

int main() { return 0; }
