#include "utils.hpp"

/* Visit 2 DFS
   ref:
   https://leetcode.com/problems/path-sum/discuss/670515/C%2B%2B-Recursive-solution-4-lines-code
*/
class Solution2 {
 public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right && root->val == targetSum) return true;

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
  }
};

/* Visit 1 DFS */
class Solution {
 public:
  void dfs(TreeNode *root, int sum, int targetSum) {
    if (!root) return;

    sum += root->val;
    if (!root->left && !root->right && sum == targetSum) {
      ans = true;
      return;
    }

    dfs(root->left, sum, targetSum);
    dfs(root->right, sum, targetSum);
  }
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) return false;
    dfs(root, 0, targetSum);
    return ans;
  }

 private:
  bool ans = false;
};

int main(int argc, char **argv) {
  vector<TreeNode *> vals{new TreeNode(5),  new TreeNode(4), new TreeNode(8),
                          new TreeNode(11), nullptr,         new TreeNode(13),
                          new TreeNode(4),  new TreeNode(7), new TreeNode(2),
                          nullptr,          nullptr,         nullptr,
                          new TreeNode(1)};
  TreeNode *root = initTreeNodes(vals);
  int targetSum = 22;
  Solution sol;
  print(sol.hasPathSum(root, targetSum));

  return 0;
}