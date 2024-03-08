#include "stdc++.h"
#include <unordered_map>
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
  void travel(TreeNode* root, int& ans, unordered_map<long, int> count, long sum, int targetSum){
    if(root == nullptr)
      return;
    sum += root->val;
    if(count.count(sum - targetSum))
      ans += count[sum - targetSum];
    if(!count.count(sum))
      count[sum] = 0;
    count[sum]++;
    travel(root->left, ans, count, sum, targetSum);
    travel(root->right, ans, count, sum, targetSum);
    count[sum]--;
  }
  int pathSum(TreeNode* root, int targetSum) {
    long sum = 0;
    int ans = 0;
    unordered_map<long, int> count;
    count[0] = 1;
    travel(root, ans, count, sum, targetSum);
    return ans;
  }
};
