
#include "stdc++.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int N = matrix[0].size();
      int col = N-1, row = 0;
      while (col>=0 && row <matrix.size()) {
        while (col >= 0 && matrix[row][col] > target) col--;
        if(col>=0 && matrix[row][col] == target)
          return true;
        row++;
      }
      return false;
    }
};
