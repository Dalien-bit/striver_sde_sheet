#include <bits/stdc++.h>
using namespace std;

class Solution {
  const int INF = 100000000;

public:
  vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {
    vector<int> dist(V, INF);
    dist[S] = 0;
    for (int i = 1; i < V; i++) {
      for (vector<int> &edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        if (dist[u] != INF and dist[u] + wt < dist[v]) {
          dist[v] = dist[u] + wt;
        }
      }
    }

    for (vector<int> &edge : edges) {
      int u = edge[0], v = edge[1], wt = edge[2];
      if (dist[u] != INF and dist[u] + wt < dist[v]) {
        return {-1};
      }
    }

    return dist;
  }
};

int main() { return 0; }