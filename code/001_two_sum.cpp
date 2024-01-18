#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mp;
    vector<int> res;
    for(int i = 0; i < nums.size(); i++) {
      int temp = nums[i];
      if(mp.count(target - temp) == 1){
        res.push_back(i);
        res.push_back(mp[target - temp]);
        break;
      }
      mp[temp] = i;
    }
    return res;
  }
};
