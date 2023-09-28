#include <bits/stdc++.h>
using namespace std;

vector<int> factorial = {1,   1,    2,     6,      24,     120,
                         720, 5040, 40320, 362880, 3628800};

string kthPermutation(int n, int k) {
  string str;
  for (int i = 0; i < n; i++)
    str.push_back(char('1' + i));
  string ans;
  int num = k;
  while (n--) {
    int deno = factorial[n], steps = (num / deno) + (num % deno != 0);
    if (steps == 0)
      steps = 1;
    num -= deno * (steps - 1);
    ans.push_back(str[steps - 1]);
    str.erase(steps - 1, 1);
  }

  return ans;
}

int main() { return 0 }