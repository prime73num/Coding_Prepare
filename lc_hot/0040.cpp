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
  bool travel(TreeNode* root, int& k, int& res){
    if(root == nullptr)
      return false;
    if(travel(root->left, k, res))
      return true;
    k--;
    if(k==0){
      res = root->val;
      return true;
    }
    if(travel(root->right, k, res))
      return true;
    return false;
  }
  int kthSmallest(TreeNode* root, int k) {
    int ans = 0;
    travel(root, k, ans);
    return ans;
  }
};
