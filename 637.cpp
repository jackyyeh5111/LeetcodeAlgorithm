#include "utils.hpp"

/* Visit 2 Recursive */
class Solution2 {
 public:
};

/* Visit 1 BFS */
class Solution1_2 {
 public:
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    if (!root) return ans;

    std::queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
      int size = queue.size();
      double level_sum = 0.0;
      for (int i = 0; i < size; i++) {
        TreeNode *node = queue.front();
        queue.pop();
        level_sum += node->val;

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }

      ans.push_back(level_sum / size);
    }

    return ans;
  }
};

/* Visit 1 BFS */
/* Wrong answer
    Runtime Error Message:
        Line 27: Char 19: runtime error: signed integer overflow: 2147483647 +
        2147483647 cannot be represented in type 'int' (solution.cpp) SUMMARY:
        UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:36:19 Last

    executed input: [2147483647,2147483647,2147483647]
*/
class Solution1_1 {
 public:
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    if (!root) return ans;

    std::queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
      int size = queue.size();
      int level_sum = 0; // Should use double here.
      for (int i = 0; i < size; i++) {
        TreeNode *node = queue.front();
        queue.pop();
        level_sum += node->val;

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }

      ans.push_back(level_sum / (double)size);
    }

    return ans;
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