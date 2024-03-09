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
  int travel(TreeNode* root, int& max_sum){
    if(root == nullptr)
      return 0;
    int l = travel(root->left, max_sum);
    int r = travel(root->right, max_sum);
    int sum = root->val;
    if(l > 0)
      sum += l;
    if(r > 0)
      sum += r;
    if(sum > max_sum)
      max_sum = sum;
    int ans = root->val;
    int longer = max(l,r);
    return longer>0? longer+ans:ans;
  }
  int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    travel(root, ans);
    return ans;
  }
};
