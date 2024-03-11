#include "stdc++.h"
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
      int s = 0, e = nums.size()-1;
      while (s<e) {
        int mid = (s+e) / 2;
        int temp = nums[mid];
        if(temp < nums[nums.size()-1])
          e = mid;
        else
         s = mid + 1;
      }
      return nums[s];
    }
};
