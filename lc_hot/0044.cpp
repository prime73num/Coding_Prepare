#include "stdc++.h"
#include <vector>
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
  TreeNode* travel(vector<int> pre, vector<int> inorder,
                   int pre_s, int pre_e, int in_s,
                   int in_e) {
    if(pre_s>pre_e)
      return nullptr;
    TreeNode* root = new TreeNode();
    int root_val = pre[pre_s];
    root->val = root_val;
    int i;
    for(i = in_s; i<=in_e; i++){
      if(inorder[i] == root_val)
        break;
    }
    root->left = travel(pre, inorder, pre_s+1, pre_s+i-in_s, in_s, i-1);
    root->right = travel(pre, inorder, pre_s+1+i-in_s, pre_e, i+1, in_e);
    return root;
  }
  TreeNode* buildTree(vector<int>& preorder,
                      vector<int>& inorder) {
    return travel(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
  }
};
