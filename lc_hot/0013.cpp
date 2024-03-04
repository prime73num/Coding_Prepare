#include "stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> ans;
      int all_mul = 1;
      int all_but_zero = 1;
      int count_zero = 0;
      for(int n:nums){
        all_mul *= n;
        if(n!=0)
          all_but_zero *= n;
        if(n==0)
          count_zero++;
      }
      for(int n : nums){
        if(n==0 && count_zero==1)
          ans.push_back(all_but_zero);
        else if (n==0 && count_zero > 1)
          ans.push_back(0);
        else
          ans.push_back(all_mul/n);
      }
      return ans;
    }
};
