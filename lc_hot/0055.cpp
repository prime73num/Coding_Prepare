#include "stdc++.h"

using namespace std;

class Solution {
public:
  bool travel(vector<vector<char>>& board, string& word,
              int idx, int row, int col) {
    if (idx == word.size())
      return true;

    int m = board.size(), n = board[0].size();
    if(!(row >= 0 && row < m && col >= 0 && col < n))
      return false;

    if(board[row][col] != word[idx])
      return false;

    char temp = board[row][col];
    board[row][col] = 0;
    if(travel(board, word, idx+1, row+1, col)){
      board[row][col] = temp;
      return true;
    }
    if(travel(board, word, idx+1, row-1, col)){
      board[row][col] = temp;
      return true;
    }
    if(travel(board, word, idx+1, row, col+1)){
      board[row][col] = temp;
      return true;
    }
    if(travel(board, word, idx+1, row, col-1)){
      board[row][col] = temp;
      return true;
    }
    board[row][col] = temp;
    return false;
  }
  bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i<board.size(); i++){
      for(int j = 0; j<board[0].size(); j++){
        if(travel(board, word, 0, i, j))
          return true;
      }
    }
    return false;
  }
};
