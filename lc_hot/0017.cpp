#include "stdc++.h"

using namespace std;



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int mid = (n+1) / 2;
      for(int i = 0; i<mid; i++){
        for(int j = i; j<n-1-i; j++){
          int row = i, col = j;
          int prev = matrix[row][col];
          for(int times = 0; times<4; times++){
            int temp = matrix[col][n-1-row];
            matrix[col][n-1-row] = prev;
            prev = temp;

            temp = row;
            row = col;
            col = n-1-temp;
          }
        }
      }
    }
};
