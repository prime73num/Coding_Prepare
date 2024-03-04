#include "stdc++.h"


using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int N = nums.size();
      for(int i = 0; i<N; i++){
        if(nums[i] <= 0)
          nums[i] = N+1;
      }
      for(int i = 0; i<N; i++){
        if(nums[i] == 0)
          continue;
        int p = nums[i];
        while (p >= 1 && p <= N) {
          int temp = nums[p-1];
          nums[p-1] = 0;
          p = temp;
        }
      }
      int ans = N+1;
      for(int i = 0; i<N; i++){
        if(nums[i]!=0){
          ans = i+1;
          break;
        }
      }
      return ans;
    }
};
