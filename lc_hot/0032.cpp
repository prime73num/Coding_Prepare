#include "stdc++.h"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  void travel(vector<int> &ans, TreeNode* root){
    if(root == nullptr)
      return;
    travel(ans, root->left);
    ans.push_back(root->val);
    travel(ans, root->right);
  }
   vector<int> inorderTraversal(TreeNode* root) {
     vector<int> ans;
     travel(ans, root);
     return ans;
   }
};
