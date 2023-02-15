#include "utils.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution3 {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* node = root;
    vector<int> ans;
    while (!stk.empty() || node) {
      while (node) {
        stk.push(node);
        if (node->left) {
          node = node->left;
        } else {
          node = node->right;
        }
      }

      node = stk.top();
      ans.push_back(node->val);
      stk.pop();
      if (!stk.empty() && stk.top()->left == node) {
        node = stk.top()->right;
      } else {
        node = nullptr;
      }
    }

    return ans;
  }
};

/* Iterative */
class Solution2 {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* node = root;
    vector<int> ans;
    while (node || !stk.empty()) {
      if (node) {
        ans.push_back(node->val);
        stk.push(node);
        node = node->right;
      } else {
        node = stk.top();
        node = node->left;
        stk.pop();
      }
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};

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

int main() {
  vector<TreeNode*> vals{
      new TreeNode(3),
      new TreeNode(1),
      new TreeNode(2),
  };
  TreeNode* root = initTreeNodes(vals);

  Solution3 sol;
  vector<int> ans = sol.postorderTraversal(root);
  print(ans);

  return 0;
}