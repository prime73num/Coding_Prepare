#include "stdc++.h"
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int s = 0, e = nums.size()-1;
      int ans = nums.size();
      while (s <= e) {
        int mid = (s+e) / 2;
        if(nums[mid] >= target){
          ans = mid;
          e = mid - 1;
        } else {
          s = mid + 1;
        }
      }
      return ans;
    }
};
