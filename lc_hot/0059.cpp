#include "stdc++.h"
using namespace std;



class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int left = -1;
    int s = 0, e = nums.size()-1;
    while (s<=e) {
      int mid = (s+e) / 2;
      if(nums[mid] < target){
        left = mid;
        s = mid + 1;
      } else {
        e = mid - 1;
      }
    }
    int right = nums.size();
    s = 0, e = nums.size()-1;
    while (s<=e) {
      int mid = (s+e) / 2;
      if(nums[mid] > target){
        right = mid;
        e = mid - 1;
      } else {
        s = mid + 1;
      }
    }
    if(left + 1 == right)
      return {-1, -1};
    return {left + 1, right - 1};
  }
};
