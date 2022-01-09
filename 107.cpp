#include "utils.hpp"

/* Ref:
    https://leetcode.com/problems/binary-tree-level-order-traversal-ii/discuss/1219348/C%2B%2B-Clean-Short-Recursive-and-Iterative-Solutions-No-Reverse-WithWithout-Queue
 */

/* visit 2 */
/* Recursive */
class Solution2 {
 public:
  void rec(TreeNode *root, int level) {
    if (!root) return;
    ans[depth - level - 1].push_back(root->val);
    rec(root->left, level + 1);
    rec(root->right, level + 1);
  }

  int getDepth(TreeNode *root) {
    if (!root) return 0;
    return std::max(getDepth(root->left), getDepth(root->right)) + 1;
  }
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    depth = getDepth(root);
    ans.assign(depth, {});
    rec(root, 0);
    return ans;
  }

 private:
  vector<vector<int>> ans;
  int depth;
};

/* visit 1 */
class Solution1_2 {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;

    std::queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
      vector<int> level_ans;
      for (int i = 0; i < queue.size(); i++) {
        TreeNode *node = queue.front();
        queue.pop();
        level_ans.push_back(node->val);

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }

      ans.insert(ans.begin(), level_ans);
    }

    return ans;
  }
};

/* Visit 1 wrong answer */
class Solution1_1 {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;

    std::queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
      vector<int> level_ans;

      // the line is wrong.
      // queue.size() will be changed inside the for loop.
      for (int i = 0; i < queue.size(); i++) {
        TreeNode *node = queue.front();
        queue.pop();
        level_ans.push_back(node->val);

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }

      ans.insert(ans.begin(), level_ans);
    }

    return ans;
  }
};

int main(int argc, char **argv) {
  vector<TreeNode *> vals{new TreeNode(3), new TreeNode(9), new TreeNode(20),
                          nullptr,         nullptr,         new TreeNode(15),
                          new TreeNode(7)};
  TreeNode *root = initTreeNodes(vals);

  Solution2 sol;
  vector<vector<int>> ans = sol.levelOrderBottom(root);
  print(ans);

  return 0;
}