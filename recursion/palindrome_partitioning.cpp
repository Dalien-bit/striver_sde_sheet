#include <bits/stdc++.h>
using namespace std;

class PalindromePartitioning {
  vector<string> parts;
  vector<vector<string>> ans;

  bool isPalindrome(string &str, int st, int en) {
    int l, r;
    (en - st + 1) & 1 ? l = r = (st + en) >> 1 : r = (l = (st + en) >> 1) + 1;
    while (l >= st)
      if (str[l--] != str[r++])
        return false;
    return true;
  }

  void util(string &str, int st) {
    if (st == str.size()) {
      ans.push_back(parts);
    }
    for (int i = st; i < str.size(); i++) {
      if (isPalindrome(str, st, i)) {
        parts.push_back(str.substr(st, i - st + 1));
        util(str, i + 1);
        parts.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    util(s, 0);
    return ans;
  }
};

int main() { return 0; }