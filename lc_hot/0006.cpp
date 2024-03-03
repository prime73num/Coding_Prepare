#include "stdc++.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > res;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int i, j, k;
    i = 0;
    while (i < size) {
      if (i != 0 && nums[i] == nums[i - 1]) {
        i++;
        continue;
      }
      j = i + 1;
      k = size-1;
      while (j<k) {
        int sum = nums[i]+nums[j]+nums[k];
        if(sum==0)
          res.push_back({nums[i], nums[j],nums[k]});
        if(sum >= 0){
          int temp = nums[k];
          while (k>=0 && nums[k] == temp) k--;
        }
        if(sum <= 0){
          int temp = nums[j];
          while (j<size && nums[j]==temp) j++;
        }
      }
      i++;
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  vector<int> test;
  Solution s;
  test.push_back(4);
  test.push_back(1);
  test.push_back(2);
  test.push_back(2);
  s.threeSum(test);

  return 0;
}
