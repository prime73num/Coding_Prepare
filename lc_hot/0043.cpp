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
  void travel(TreeNode* root, TreeNode* &tail){
    if(root == nullptr)
      return;
    tail->right = root;
    tail->left = nullptr;
    tail = root;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    travel(left, tail);
    travel(right, tail);
  }
  void flatten(TreeNode* root) {
    TreeNode s;
    TreeNode* tail = &s;
    travel(root, tail);
  }
};
