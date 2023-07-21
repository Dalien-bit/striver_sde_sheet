#include <bits/stdc++.h>
using namespace std;

class SolutionBFS {
  queue<int> q;
  int node, color[100];

public:
  bool isBipartite(vector<vector<int>> &graph) {
    memset(color, -1, sizeof(graph.size()));
    for (int i = 0; i < graph.size(); i++) {
      if (color[i] >= 0)
        continue;
      color[i] = 1;
      q.push(i);
      while (!q.empty()) {
        node = q.front();
        q.pop();
        for (int it : graph[node]) {
          if (color[it] == -1) {
            color[it] = 1 - color[node];
            q.push(it);
          } else if (color[it] == color[node]) {
            return false;
          }
        }
      }
    }
    return true;
  }
};

class SolutionDFS {
private:
  bool dfs(int node, int col, int color[], vector<int> adj[]) {
    color[node] = col;

    // traverse adjacent nodes
    for (auto it : adj[node]) {
      // if uncoloured
      if (color[it] == -1) {
        if (dfs(it, !col, color, adj) == false)
          return false;
      }
      // if previously coloured and have the same colour
      else if (color[it] == col) {
        return false;
      }
    }

    return true;
  }

public:
  bool isBipartite(int V, vector<int> adj[]) {
    int color[V];
    for (int i = 0; i < V; i++)
      color[i] = -1;

    // for connected components
    for (int i = 0; i < V; i++) {
      if (color[i] == -1) {
        if (dfs(i, 0, color, adj) == false)
          return false;
      }
    }
    return true;
  }
};

int main() { return 0; }