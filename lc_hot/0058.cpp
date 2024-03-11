#include "stdc++.h"
#include <vector>
using namespace std;

class Solution {
public:

  bool searchMatrix(vector<vector<int>>& matrix,
                    int target) {
    int row_num = matrix.size();
    vector<int> row(row_num);
    for(int i = 0; i<row_num; i++)
      row[i] = matrix[i][0];
    int s = 0, e = row_num-1, idx = -1;
    while (s<=e) {
      int mid = (s+e) / 2;
      if(row[mid] <= target){
        idx = mid;
        s = mid + 1;
      } else {
        e = mid - 1;
      }
    }
    if(idx == -1)
      return false;
    vector<int> &temp = matrix[idx];
    s = 0, e = temp.size()-1, idx = -1;
    while (s<=e) {
      int mid = (s+e) / 2;
      if(temp[mid] <= target){
        idx = mid;
        s = mid + 1;
      } else {
        e = mid - 1;
      }
    }
    if(idx == -1)
      return false;
    return temp[idx] == target;
  }
};
