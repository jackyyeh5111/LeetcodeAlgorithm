#include "utils.hpp"

/* Visit 2 Iterative BFS */
class Solution2 {
 public:
  int sumNumbers(TreeNode *root) {
    
  }
};

/* Visit 1 DFS
    Use int ans instead of vector<int> ans. (Simpler)
 */
class Solution1_2 {
 public:
  void dfs(TreeNode *root, int num, int &ans) {
    if (!root) return;
    num = num * 10 + root->val;
    if (!root->left && !root->right) {
      ans += num;
    }

    dfs(root->left, num, ans);
    dfs(root->right, num, ans);
  }

  int sumNumbers(TreeNode *root) {
    int ans = 0;
    dfs(root, 0, ans);
    return ans;
  }
};

/* Visit 1 DFS
 */
class Solution1_1 {
 public:
  void dfs(TreeNode *root, int num, vector<int> &ans) {
    if (!root) return;
    num = num * 10 + root->val;
    if (!root->left && !root->right) {
      ans.push_back(num);
      return;
    }

    dfs(root->left, num, ans);
    dfs(root->right, num, ans);
  }

  int sumNumbers(TreeNode *root) {
    vector<int> ans;
    dfs(root, 0, ans);
    return std::accumulate(ans.begin(), ans.end(), 0);
  }
};

int main(int argc, char **argv) {
  vector<TreeNode *> vals{new TreeNode(1), new TreeNode(2), new TreeNode(3)};
  TreeNode *root = initTreeNodes(vals);
  //   int targetSum = 22;
  Solution1_2 sol;
  int ans = sol.sumNumbers(root);
  //   print(ans);
  std::cout << "ans: " << ans << '\n';

  return 0;
}