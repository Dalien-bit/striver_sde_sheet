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

int main() { return 0; }
