#include "stdc++.h"
#include <utility>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int len = nums.size();
      for(int i = 0; i<len-1; i++){
        for(int j = 0; j<len-1-i; j++){
          if(nums[j]!=0)
            continue;
          swap(nums[j], nums[j+1]);
        }
      }
    }
};
