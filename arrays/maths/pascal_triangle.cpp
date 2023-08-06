#include <bits/stdc++.h>
using namespace std;

// nC2 = n * (n - 1) /  2 * 1

// nC3 = n * (n - 1) * (n - 3) / 3 * 2 * 1

// nC4 = n * (n - 1) * (n - 3) * (n - 4) / 4 * 3 *  2 * 1

// nCr = n * (n - 1) * (n - 3) * .... (n - r) / r * (r - 1) * (r - 2) * ... 3 * 2 * 1

// nCr = n * (n - 1) * (n - 3) * .... (n - r) / 1 * 2 * 3 * .... (r - 2) * (r - 1) * r

long long nCr(int n, int r) {
  long long res = 1;

  for (int i = 0; i < r; i++) {
    res = res * (n - i);
    res = res / (i + 1);
  }
  return res;
}

void pascalTriangleRow(int n) {
  for (int c = 1; c <= n; c++) {
    cout << nCr(n - 1, c - 1) << " ";
  }
  cout << "n";
}

vector<vector<int>> pascalTriangle(int n) {
  vector<vector<int>> ans;

  for (int row = 1; row <= n; row++) {
    vector<int> tempLst; // temporary list
    for (int col = 1; col <= row; col++) {
      tempLst.push_back(nCr(row - 1, col - 1));
    }
    ans.push_back(tempLst);
  }
  return ans;
}

int main() { return 0; }