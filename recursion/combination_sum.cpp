#include<bits/stdc++.h>
using namespace std;

int target, sum;
vector<int> subset;
vector<vector<int>> ans;

void util(vector<int> &v, int i) {
  if (i >= v.size()) {
    if (sum == target) {
      ans.push_back(subset);
    }
    return;
  }

  util(v, i + 1);

  sum += v[i];
  subset.push_back(v[i]);
  util(v, i + 1);
  subset.pop_back();
  sum -= v[i];
}

void init(int k) {
  subset.clear(), ans.clear();
  target = k, sum = 0;
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k) {
  init(k);
  util(arr, 0);
  return ans;
}

int main() { return 0; }