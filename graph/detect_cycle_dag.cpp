#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
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
				
			int topoSize = 0;
			
			while (!q.empty()) {
				int node = q.front();
				q.pop();

				topoSize++;

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

int main() {
	return 0;
}
