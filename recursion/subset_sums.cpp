#include <bits/stdc++.h>
using namespace std;

// Given a list arr of N integers, print sums of all subsets in it.

// Time Complexity: O(pow(2, n))
// Auxiliary Space: O(pow(2, n))

class Solution {
  vector<int> ans;

public:
  void subsetSumsUtil(vector<int> &arr, int i, int sum) {
    if (i >= arr.size()) {
      ans.push_back(sum);
      return;
    }
    subsetSumsUtil(arr, i + 1, sum);
    subsetSumsUtil(arr, i + 1, sum + arr[i]);
  }
  vector<int> subsetSums(vector<int> &arr, int N) {
    subsetSumsUtil(arr, 0, 0);

    return ans;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }
    Solution ob;
    vector<int> ans = ob.subsetSums(arr, N);
    sort(ans.begin(), ans.end());
    for (auto sum : ans) {
      cout << sum << " ";
    }
    cout << endl;
  }
  return 0;
}