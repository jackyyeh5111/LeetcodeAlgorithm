#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

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

/*
    initTreeNodes usage:
    int main(int argc, char **argv) {
        vector<TreeNode *> vals{new TreeNode(3), new TreeNode(9), new
   TreeNode(20), nullptr,         nullptr,         new TreeNode(15), new
   TreeNode(7)}; TreeNode *root = initTreeNodes(vals);

        Solution2 sol;
        vector<vector<int>> ans = sol.levelOrderBottom(root);
        print(ans);

        return 0;
    }
 */
TreeNode *initTreeNodes(vector<TreeNode *> nodes) {
  // assign child to each nodes
  int len = nodes.size();
  for (int i = 0; i < len; i++) {
    if (!nodes[i]) continue;

    int left_child_idx = 2 * i + 1;
    int right_child_idx = 2 * i + 2;
    if (left_child_idx < len) nodes[i]->left = nodes[left_child_idx];
    if (right_child_idx < len) nodes[i]->right = nodes[right_child_idx];
  }

  return nodes[0];
}

template <typename T>
void print(vector<vector<T>> &vecs) {
  for (vector<T> vec : vecs) {
    for (auto val : vec) std::cout << val << ' ';
    std::cout << '\n';
  }
}

template <typename T>
void print(vector<T> &vecs) {
  for (auto val : vecs) std::cout << val << ' ';
  std::cout << '\n';
}

// template <typename T>
// void print(T val) {
//   std::cout << val << '\n';
// }
