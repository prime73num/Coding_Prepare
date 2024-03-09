#include "stdc++.h"
#include <vector>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses,
                 vector<vector<int>>& prerequisites) {
    vector<vector<int>> edge(numCourses);
    vector<int> count(numCourses, 0);
    for (auto& e : prerequisites) {
      edge[e[1]].push_back(e[0]);
      count[e[0]]++;
    }
    int count_add = 0;
    while (true) {
      bool find = false;
      int p;
      for (p = 0; p < numCourses; p++) {
        if (count[p] == 0) {
          find = true;
          break;
        }
      }
      if (!find)
        break;
      count[p] = -1;
      count_add++;
      for (int i = 0; i < edge[p].size(); i++) {
        count[edge[p][i]]--;
      }
    }
    return count_add == numCourses;
  }
};
