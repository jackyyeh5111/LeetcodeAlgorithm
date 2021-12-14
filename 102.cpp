#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/* visit 1 */
/**
 * Definition for a binary tree node.
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;

    std::queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
      int num_level = queue.size();
      vector<int> level_ans;

      for (int i = 0; i < num_level; i++) {
        TreeNode *node = queue.front();
        level_ans.push_back(node->val);
        queue.pop();

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }

      ans.push_back(level_ans);
    }

    return ans;
  }
};

int main(int argc, char **argv) {
  Solution sol;
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

  for (int n : sol.findDisappearedNumbers(nums)) {
    std::cout << n << ' ';
  }
  std::cout << '\n';

  //   intervals = {{1, 3}, {6, 9}};
  //   newInterval = {2, 5};
  //   for (vector<int> ans : sol.insert(intervals, newInterval)) {
  //     for (int n : ans) std::cout << n << ' ';
  //     std::cout << '\n';
  //   }
  //   std::cout << '\n';

  return 0;
}