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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<TreeNode*> queue;
    vector<vector<int>> ans;
    queue.push_back(root);
    int s = 0, e = queue.size();
    while (s < e) {
      vector<int> level;
      for (int i = s; i < e; i++) {
        if(queue[i] == nullptr)
          continue;
        level.push_back(queue[i]->val);
        queue.push_back(queue[i]->left);
        queue.push_back(queue[i]->right);
      }
      if(!level.empty())
        ans.push_back(level);
      s = e;
      e = queue.size();
    }
    return ans;
  }
};
