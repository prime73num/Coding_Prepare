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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root == nullptr)
      return ans;
    vector<TreeNode*> queue;
    queue.push_back(root);
    int s = 0, e = queue.size();
    while (s<e) {
      ans.push_back(queue[s]->val);
      for(int i = s; i<e; i++){
        TreeNode* temp = queue[i];
        if(temp->right != nullptr)
          queue.push_back(temp->right);
        if(temp->left != nullptr)
          queue.push_back(temp->left);
      }
      s = e;
      e = queue.size();
    }
    return ans;
  }
};
