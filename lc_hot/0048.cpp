#include "stdc++.h"
using namespace std;

class Solution {
public:
  void travel(vector<vector<int>>& grid, int i, int j, int out_time) {
    int m = grid.size(), n = grid[0].size();
    if (!(i >= 0 && i < m && j >= 0 && j < n))
      return;
    int &temp = grid[i][j];
    if (temp == 0)
      return;
    if(temp == 2 && out_time > 3)
      return;
    if(temp >= 3 && temp <= out_time)
      return;
    temp = out_time;
    travel(grid, i - 1, j, out_time+1);
    travel(grid, i + 1, j, out_time+1);
    travel(grid, i, j - 1, out_time+1);
    travel(grid, i, j + 1, out_time+1);
  }
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if(grid[i][j] == 2){
          travel(grid, i, j, 3);
        }
      }
    }
    int ans = 3;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int temp = grid[i][j];
        if(temp > ans)
          ans = temp;
        if(temp == 1)
          return -1;
      }
    }
    return ans - 3;
  }
};
