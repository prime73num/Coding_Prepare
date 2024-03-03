#include "stdc++.h"
using namespace std;

class Solution {
public:
  int maxArea(vector<int>& height) {
    int res = 0;
    int s = 0, e = height.size() - 1;
    while (s < e) {
      int area = min(height[s], height[e]) * (e - s);
      if (area > res)
        res = area;
      if (height[s] > height[e]) {
        e--;
      } else {
        s++;
      }
    }
    return res;
  }
};
