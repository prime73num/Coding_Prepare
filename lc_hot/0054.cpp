#include "stdc++.h"
#include <vector>

using namespace std;

class Solution {
public:
  void travel(vector<string> &ans, int idx, string &check, string &par){
    if(idx==0){
      if(check.empty())
        ans.push_back(string(par));
      return;
    }
    par.push_back('(');
    check.push_back('(');
    travel(ans, idx-1, check, par);
    par.pop_back();
    check.pop_back();

    if(check.empty())
      return;
    par.push_back(')');
    check.pop_back();
    travel(ans, idx-1, check, par);
    check.push_back('(');
    par.pop_back();
  }
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string check, par;
    travel(ans, 2*n, check, par);
    return ans;
  }
};
