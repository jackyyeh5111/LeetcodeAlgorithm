#include "utils.hpp"

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;
    postorder(root, ans);
    return ans;
  }

  void postorder(TreeNode* root, vector<int>& ans) {
    if (!root) return;
    if (root->left) postorder(root->left, ans);
    if (root->right) postorder(root->right, ans);
    ans.push_back(root->val);
  }
};