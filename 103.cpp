#include "utils.hpp"

/* Visit 2 Recursive */
class Solution2 {
 public:
  void dfs(TreeNode *root, int level) {
    if (!root) return;
    if (level + 1 >= ans.size()) ans.resize(level + 1, {});

    if (level % 2)
      ans[level].insert(ans[level].begin(), root->val);
    else
      ans[level].push_back(root->val);

    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
  }

  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    dfs(root, 0);
    return ans;
  }

 private:
  vector<vector<int>> ans;
};

/* Visit 1 BFS */
class Solution1 {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    std::queue<TreeNode *> queue;
    queue.push(root);

    int level = 0;
    while (!queue.empty()) {
      vector<int> level_ans;
      int size = queue.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = queue.front();
        queue.pop();
        if (level % 2)  // even level
          level_ans.insert(level_ans.begin(), node->val);
        else
          level_ans.push_back(node->val);

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }

      ans.push_back(level_ans);
      level++;
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
  vector<vector<int>> ans = sol.zigzagLevelOrder(root);
  print(ans);

  return 0;
}