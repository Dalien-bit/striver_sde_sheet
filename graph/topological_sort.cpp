#include <bits/stdc++.h>
using namespace std;

// topological sorting only available in Directed Acyclic graphs

class SolutionDFS {
  stack<int> st;

public:
  void dfs(vector<int> adj[], int node, bool vis[]) {
    vis[node] = true;

    for (int child : adj[node]) {
      if (!vis[child]) {
        dfs(adj, child, vis);
      }
    }

    st.push(node);
  }
  vector<int> topoSort(int V, vector<int> adj[]) {
    bool vis[V] = {0};
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        dfs(adj, i, vis);
      }
    }
    int i = 0;
    vector<int> ans(V);
    while (!st.empty()) {
      ans[i++] = st.top();
      st.pop();
    }

    return ans;
  }
};

class SolutionBFS {
public:
  // checking cycle in graph using topological sorting 
  // if size of toposort == V then its a DAG else its cyclic
  bool isCyclic(int V, vector<int> adj[]) {
    int indegree[V] = {0};

    for (int i = 0; i < V; i++) {
      for (int j = 0; j < adj[i].size(); j++) {
        indegree[adj[i][j]]++;
      }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    int topoSize = 0; // use vector if you want to store topo sort

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      topoSize++; // push into vector(LIFO) if storing topo sort

      for (int child : adj[node]) {
        indegree[child]--;
        if (indegree[child] == 0) {
          q.push(child);
        }
      }
    }
    return topoSize != V;
  }
};

int main() { return 0; }