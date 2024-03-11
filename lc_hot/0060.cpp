#include "stdc++.h"
using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;
    while (s <= e) {
      int mid = (s + e) / 2;
      if (nums[mid] == target)
        return mid;
      if (nums[mid] >= nums[0]) {
        if (nums[mid] > target && target >= nums[0]) {
          e = mid - 1;
        } else {
          s = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[nums.size()-1]) {
          s = mid + 1;
        } else {
          e = mid - 1;
        }
      }
    }
    return -1;
  }
};
