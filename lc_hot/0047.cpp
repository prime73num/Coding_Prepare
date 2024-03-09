#include "stdc++.h"
using namespace std;

class Solution {
public:
  void travel(vector<vector<char>>& grid, int i, int j){
    int m = grid.size(), n = grid[0].size();
    if(!(i>=0 && i<m && j>=0 && j<n))
      return;
    if(grid[i][j] == '0')
      return;
    grid[i][j] = '0';
    travel(grid, i-1, j);
    travel(grid, i+1, j);
    travel(grid, i, j-1);
    travel(grid, i, j+1);
  }
  int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        char& c = grid[i][j];
        if (c == '1') {
          count++;
          travel(grid, i, j);
        }
      }
    }
    return count;
  }
};
