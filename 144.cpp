#include "utils.hpp"

/*
ref:
https://leetcode.com/problems/binary-tree-postorder-traversal/solutions/45551/preorder-inorder-and-postorder-iteratively-summarization/
https://leetcode.com/problems/binary-tree-preorder-traversal/discuss/45466/C%2B%2B-Iterative-Recursive-and-Morris-Traversal
*/

/* Iterative (more general approach) */
class Solution3 {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;
    stack<TreeNode*> stk;
    TreeNode* node = root;
    while (node || !stk.empty()) {
      if (node) {
        ans.push_back(node->val);
        stk.push(node);
        node = node->left;
      } else {
        node = stk.top();
        node = node->right;
        stk.pop();
      }
    }
    return ans;
  }
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

/* Iterative (wrong answer!) */
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;
    stack<TreeNode*> stk{deque<TreeNode*>{root}};
    while (!stk.empty()) {
      TreeNode* node = stk.top();
      ans.push_back(node->val);
      stk.pop();
      while (node->left) {
        node = node->left;
        stk.push(node);
        ans.push_back(node->val);
      }

      while (node->right) {
        node = node->right;
        stk.push(node);
        ans.push_back(node->val);
      }
    }

    return ans;
  }
};

/* Recursive */
class SolutionRecursive {
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

int main() {
  vector<TreeNode*> vals{
      new TreeNode(1),
      nullptr,
      new TreeNode(2),
      new TreeNode(3),
  };
  TreeNode* root = initTreeNodes(vals);

  Solution3 sol;
  vector<int> ans = sol.preorderTraversal(root);
  print(ans);

  return 0;
}