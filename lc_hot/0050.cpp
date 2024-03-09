#include "stdc++.h"
#include <vector>

using namespace std;

class Solution {
public:
  void travel(vector<vector<int>> &ans, vector<int>& nums, vector<int> &par){
    int find = false;
    for(int i = 0; i<nums.size(); i++){
      if(nums[i] == -15)
        continue;
      find = true;
      int temp = nums[i];
      nums[i] = -15;
      par.push_back(temp);
      travel(ans, nums, par);
      par.pop_back();
      nums[i] = temp;
    }
    if(!find)
      ans.push_back(vector(par));
  }
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> par;
    travel(ans, nums, par);
    return ans;
  }
};
