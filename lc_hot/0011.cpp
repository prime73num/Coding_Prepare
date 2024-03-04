#include "stdc++.h"
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
  return a[0] < b[0];
}

class Solution {
public:
  vector<vector<int>>
  merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end(), cmp);
    int p = 0, len = intervals.size();
    while (p < len) {
      int start = intervals[p][0];
      int end = intervals[p][1];
      p++;
      while (p < len && intervals[p][0] <= end) {
        end = max(end, intervals[p][1]);
        p++;
      }
      ans.push_back({start, end});
    }
    return ans;
  }
};
