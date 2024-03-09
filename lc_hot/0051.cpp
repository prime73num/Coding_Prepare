
#include "stdc++.h"
#include <vector>
using namespace std;

class Solution {
public:
  void travel(vector<vector<int>> &ans, vector<int> &nums, int idx, vector<int> par){
    if(idx == nums.size()){
      ans.push_back(vector(par));
      return;
    }
    travel(ans, nums, idx+1, par);
    par.push_back(nums[idx]);
    travel(ans, nums, idx+1, par);
    par.pop_back();
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> par;
    int idx = 0;
    travel(ans, nums, idx, par);
    return ans;
  }
};
