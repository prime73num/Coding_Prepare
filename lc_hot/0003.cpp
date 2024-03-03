
#include "stdc++.h"
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> num_set;
      for(int i = 0; i<nums.size(); i++){
        num_set.insert(nums[i]);
      }
      int maxlen = 0;
      for(int i = 0; i<nums.size(); i++){
        int num = nums[i];
        if(num_set.count(num-1))
          continue;
        int count = 0;
        while (num_set.count(num)) {
          count++;
          num++;
        }
        if(count>maxlen)
          maxlen = count;
      }
      return maxlen;
    }
};
