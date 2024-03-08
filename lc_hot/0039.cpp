#include <climits>
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
  bool travel(TreeNode* root, long long& prev){
    if(root == nullptr)
      return true;
    if(!travel(root->left, prev))
      return false;
    if(root->val <= prev)
      return false;
    prev = root->val;
    if(!travel(root->right, prev))
      return false;
    return true;
  }
  bool isValidBST(TreeNode* root) {
    long long prev = LONG_MIN;
    return travel(root, prev);
  }
};
