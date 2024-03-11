#include "stdc++.h"
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> idx;
    vector<int> ans(temperatures.size());
    for(int i = 0; i<temperatures.size(); i++){
      while (!idx.empty() && temperatures[idx.back()] < temperatures[i]) {
        ans[idx.back()] = i;
        idx.pop_back();
      }
      idx.push_back(i);
    }
    while (!idx.empty()) {
      int i = idx.back();
      ans[i] = i;
      idx.pop_back();
    }
    for(int i = 0; i<temperatures.size(); i++){
      ans[i] = ans[i] - i;
    }
    return ans;
  }
};
