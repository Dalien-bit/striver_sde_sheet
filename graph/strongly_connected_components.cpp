#include <bits/stdc++.h>
using namespace std;

void sortTopologicaly(vector<vector<int>> &adj, int node, stack<int> &st, int vis[]) {
  vis[node] = true;

  for (int &child : adj[node]) {
    if (!vis[child]) {
      sortTopologicaly(adj, child, st, vis);
    }
  }

  st.push(node);
}

vector<vector<int>> transpose(vector<vector<int>> &adj) {
  vector<vector<int>> tadj(adj.size());
  for (int i = 0; i < adj.size(); i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      tadj[adj[i][j]].push_back(i);
    }
  }

  return tadj;
}

void dfs(vector<vector<int>> &adj, int node, int vis[]) {
  vis[node] = true;

  for (int &child : adj[node]) {
    if (!vis[child]) {
      dfs(adj, child, vis);
    }
  }
}

class Solution {
public:
  int kosaraju(int V, vector<vector<int>> &adj) {
    int vis[V] = {false}, cnt = 0;
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            sortTopologicaly(adj, i, st, vis);
        }
    }
    vector<vector<int>> tadj = transpose(adj);
    memset(vis, 0, sizeof (vis));
    while (!st.empty()) {
      int node = st.top();
      st.pop();
      if (!vis[node]) {
        cnt++;
        dfs(tadj, node, vis);
      }
    }

    return cnt;
  }
};

int main() { return 0; }