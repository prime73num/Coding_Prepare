#include "stdc++.h"
#include <vector>
using namespace std;

class Solution {
public:
  void travel(vector<vector<int>>& ans,
              vector<int>& candidates, int idx, int target,
              vector<int>& par) {
    if (idx == candidates.size())
      return;
    int add = candidates[idx];
    int size = par.size();
    while (true) {
      if(target < 0)
        break;
      if(target == 0){
        ans.push_back(vector(par));
        break;
      }
      travel(ans, candidates, idx + 1, target, par);
      target -= add;
      par.push_back(add);
    }
    par.resize(size);
  }
  vector<vector<int>>
  combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> par;
    travel(ans, candidates, 0, target, par);
    return ans;
  }
};
