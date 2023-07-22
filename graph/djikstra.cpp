#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int INF = INT_MAX;

class Solution {
public:
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INF);
    pq.push({0, S});
    dist[S] = 0;

    while (!pq.empty()) {
      int distNode = pq.top().first, node = pq.top().second;
      pq.pop();

      for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i][0], wt = adj[node][i][1];
        if (distNode + wt < dist[child]) {
          dist[child] = distNode + wt;
          pq.push({distNode + wt, child});
        }
      }
    }

    return dist;
  }
};

typedef vector<vector<pair<int, int>>> vvpii;
class Solution {
public:
  vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
    vvpii adj(n + 1);
    for (int i = 1; i <= n; i++) {
      adj[edges[i][0]].push_back({adj[i][1], adj[i][2]});
      adj[edges[i][1]].push_back({adj[i][0], adj[i][2]});
    }
    int vis[n + 1] = {0};
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    vector<int> dist(V, INF);
    pq.push({0, S});
    dist[S] = 0;

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    while (!pq.empty()) {
      int distNode = pq.top().first, node = pq.top().second;
      pq.pop();

      for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i].first, wt = adj[node][i].second;
        if (distNode + wt < dist[child]) {
          dist[child] = distNode + wt;
          parent[child] = node;
          pq.push({distNode + wt, child});
        }
      }
    }

    vector<int> ans;
    int node = n;
    while (node != parent[node]) {
      ans.push_back(node);
      node = parent[node];
    }

    reverse(ans.begin(), ans.end());
  }
};

int main() { return 0; }
