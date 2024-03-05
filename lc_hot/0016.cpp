#include "stdc++.h"
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int rowl = 0, rowh = matrix.size() - 1, coll = 0,
        colh = matrix[0].size() - 1;
    int dir = 0;
    while (rowl <= rowh && coll <= colh) {
      if (dir == 0) {
        for (int i = coll; i <= colh; i++)
          ans.push_back(matrix[rowl][i]);
        rowl++;
      } else if (dir == 1) {
        for (int i = rowl; i <= rowh; i++)
          ans.push_back(matrix[i][colh]);
        colh--;
      } else if (dir == 2) {
        for (int i = colh; i >= coll; i--)
          ans.push_back(matrix[rowh][i]);
        rowh--;
      } else if (dir == 3) {
        for (int i = rowh; i >= rowl; i--)
          ans.push_back(matrix[i][coll]);
        coll++;
      } else {
      }
      dir = (dir + 1) % 4;
    }
    return ans;
  }
};
