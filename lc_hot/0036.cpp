#include "stdc++.h"
using namespace std;


struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int travel(TreeNode* root, int& max_len){
    if(root == nullptr)
      return -1;
    int left = travel(root->left, max_len);
    int right = travel(root->right, max_len);
    int res = 0;
    if(left != -1)
      res += left + 1;
    if(right != -1)
      res += right + 1;
    max_len = max(max_len, res);
    int longerpath = max(left, right);
    if(longerpath==-1)
      return 0;
    return longerpath+1;
  }
  int diameterOfBinaryTree(TreeNode* root) {
    int max_len = 0;
    travel(root, max_len);
    return max_len;
  }
};
