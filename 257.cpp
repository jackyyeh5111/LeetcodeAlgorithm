#include "utils.hpp"

/* Visit 1
 */
class Solution {
 public:
  void dfs(const TreeNode *root, std::string path, vector<string> &ans) {
    if (!root) return;

    path += std::to_string(root->val);
    if (!root->left && !root->right)
      ans.push_back(path);
    else
      path += "->";

    dfs(root->left, path, ans);
    dfs(root->right, path, ans);
  }

  vector<string> binaryTreePaths(TreeNode *root) {
    if (!root) return {""};

    vector<string> ans;
    dfs(root, "", ans);

    return ans;
  }
};

int main(int argc, char **argv) {
  vector<TreeNode *> vals{new TreeNode(1), new TreeNode(2), new TreeNode(3),
                          nullptr, new TreeNode(5)};

  TreeNode *root = initTreeNodes(vals);
  Solution sol;
  vector<string> ans = sol.binaryTreePaths(root);
  print(ans);

  return 0;
}