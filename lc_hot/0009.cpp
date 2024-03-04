#include "stdc++.h"
using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    int sum = 0, size = nums.size();
    int ans = 0;
    count[0] = 1;
    for (int i = 0; i < size; i++) {
      sum += nums[i];
      int target = sum - k;
      if (count.count(target))
        ans += count[target];
      if (!count.count(sum))
        count[sum] = 0;
      count[sum]++;
    }
    return ans;
  }
};
