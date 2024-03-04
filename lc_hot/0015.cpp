#include "stdc++.h"
#include <unordered_set>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      unordered_set<int> row, col;
      int m = matrix.size(), n = matrix[0].size();
      for(int r = 0; r < m; r++){
        for(int c = 0; c<n; c++){
          if(matrix[r][c] == 0){
            row.insert(r);
            col.insert(c);
          }
        }
      }
      for(int r = 0; r < m; r++){
        for(int c = 0; c<n; c++){
          if(row.count(r) || col.count(c))
            matrix[r][c] = 0;
        }
      }
    }
};
