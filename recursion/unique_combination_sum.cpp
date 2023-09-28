#include <bits/stdc++.h>
using namespace std;
int target, sum;
vector<int> subset;
vector<vector<int>> ans;

void util(vector<int> &v, int i) {
  if (sum == target)
    ans.push_back(subset);
  for (int j = i; j < v.size(); j++) {
    if (j != i && v[j] == v[j - 1])
      continue;
    subset.push_back(v[j]);
    sum += v[j];
    util(v, j + 1);
    subset.pop_back();
    sum -= v[j];
  }
}

void init(int k) {
  subset.clear(), ans.clear();
  target = k, sum = 0;
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target) {
  init(target);
  sort(arr.begin(), arr.end());
  util(arr, 0);
  return ans;
}

int main() {
  return 0;
}