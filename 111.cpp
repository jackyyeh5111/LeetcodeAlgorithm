#include "utils.hpp"

/* Visit 1 BFS */
class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (!root) return 0;
    std::queue<TreeNode *> queue;
    queue.push(root);

    int level = 0;
    while (!queue.empty()) {
      int size = queue.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = queue.front();
        queue.pop();

        if (!node->left && !node->right) return level + 1;

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }

      level++;
    }

    return level + 1;
  }
};

int main(int argc, char **argv) {
  vector<TreeNode *> vals{new TreeNode(3), new TreeNode(9), new TreeNode(20),
                          nullptr,         nullptr,         new TreeNode(15),
                          new TreeNode(7)};
  TreeNode *root = initTreeNodes(vals);

  Solution1 sol;
  vector<double> ans = sol.averageOfLevels(root);
  print(ans);

  return 0;
}