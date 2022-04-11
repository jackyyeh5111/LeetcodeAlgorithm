#include "utils.hpp"

/*
ref:
https://leetcode.com/problems/binary-tree-preorder-traversal/discuss/45466/C%2B%2B-Iterative-Recursive-and-Morris-Traversal
*/

/* Morris traversal (TODO) */
class Solution3 {
  vector<int> preorderTraversal(TreeNode* root) {}
};

/* Iterative */
class Solution2 {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};
    stack<TreeNode*> stk;
    vector<int> ans;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode* node = stk.top();
      stk.pop();
      ans.push_back(node->val);
      if (node->right) stk.push(node->right);
      if (node->left) stk.push(node->left);
    }

    return ans;
  }
};
/* Recursive */
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;
    preorder(root, ans);
    return ans;
  }

  void preorder(TreeNode* root, vector<int>& ans) {
    if (!root) return;
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
  }
};

int main() { return 0; }