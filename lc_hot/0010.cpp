#include "stdc++.h"
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int ans;
    int sum = 0, min_sum = 0;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      sum += nums[i];
      ans = max(ans, sum - min_sum);
      min_sum = min(min_sum, sum);
    }
    return ans;
  }
};
