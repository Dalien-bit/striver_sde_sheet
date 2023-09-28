#include <bits/stdc++.h>
using namespace std;
vector<int> subset;
vector<vector<int>> ans;
void util(vector<int> &v, int i) {
  ans.push_back(subset);
  for (int j = i; j < v.size(); j++) {
    if (j != i && v[j] == v[j - 1])
      continue;
    subset.push_back(v[j]);
    util(v, j + 1);
    subset.pop_back();
  }
}
void init() {
  subset.clear();
  ans.clear();
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr) {
  init();
  sort(arr.begin(), arr.end());
  util(arr, 0);
  return ans;
}

int main() { return 0; }