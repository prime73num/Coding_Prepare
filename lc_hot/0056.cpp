#include "stdc++.h"
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
  int dp[20][20];
  void travel(vector<vector<string>>& ans, string& s,
              int idx, vector<string> par) {
    if (idx == s.size()) {
      ans.push_back(vector(par));
      return;
    }
    for (int i = idx; i < s.size(); i++) {
      if (!dp[idx][i])
        continue;
      par.push_back(s.substr(idx, i - idx + 1));
      travel(ans, s, i + 1, par);
      par.pop_back();
    }
  }
  vector<vector<string>> partition(string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int l = i, r = i;
      while (l >= 0 && r < n) {
        if (s[l] != s[r])
          break;
        dp[l][r] = 1;
        l--;
        r++;
      }
    }
    for (int i = 0; i < n - 1; i++) {
      int l = i, r = i+1;
      while (l >= 0 && r < n) {
        if (s[l] != s[r])
          break;
        dp[l][r] = 1;
        l--;
        r++;
      }
    }
    vector<vector<string>> ans;
    vector<string> par;
    travel(ans, s, 0, par);
    return ans;
  }
};
