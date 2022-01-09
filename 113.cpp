#include "utils.hpp"

/* Visit 1 DFS
    ref:
    https://leetcode.com/problems/path-sum-ii/discuss/1382603/Path-Sum-II-or-DFS-%2B-BFS-wExplanation-or-2-Approaches
*/
class Solution {
 public:
  void dfs(TreeNode *root, int sum, vector<int> temp_ans,
           vector<vector<int>> &ans) {
    if (!root) return;

    int val = root->val;
    temp_ans.push_back(val);

    if (!root->left && !root->right && val == sum) {
      ans.push_back(temp_ans);
      return;
    }

    dfs(root->left, sum - val, temp_ans, ans);
    dfs(root->right, sum - val, temp_ans, ans);
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> ans;
    if (!root) return ans;

    vector<int> left_ans, right;
    dfs(root, targetSum, {}, ans);

    return ans;
  }
};

int main(int argc, char **argv) {
  vector<TreeNode *> vals{new TreeNode(5),  new TreeNode(4), new TreeNode(8),
                          new TreeNode(11), nullptr,         new TreeNode(13),
                          new TreeNode(4),  new TreeNode(7), new TreeNode(2),
                          nullptr,          nullptr,         new TreeNode(5),
                          new TreeNode(1)};
  TreeNode *root = initTreeNodes(vals);
  int targetSum = 22;
  Solution sol;
  vector<vector<int>> ans = sol.pathSum(root, targetSum);
  print(ans);

  return 0;
}