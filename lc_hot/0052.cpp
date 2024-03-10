#include "stdc++.h"
using namespace std;

class Solution {
public:
  void travel(vector<string>& ans, string map[],
              string& digits, int idx, string& par) {
    if (idx == digits.size()) {
      ans.push_back(string(par));
      return;
    }
    string& temp = map[digits[idx] - '2'];
    for (char c : temp) {
      par.push_back(c);
      travel(ans, map, digits, idx + 1, par);
      par.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.empty())
      return ans;
    string map[] = {"abc", "def",  "ghi", "jkl",
                    "mno", "pqrs", "tuv", "wxyz"};
    string par;
    travel(ans, map, digits, 0, par);
    return ans;
  }
};
