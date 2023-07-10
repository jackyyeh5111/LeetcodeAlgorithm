/**
 * The benefit of having tail recursion, is that for certain programming
 * languages (e.g. C++) the compiler could optimize the memory allocation of
 * call stack by reusing the same space for every recursive call, rather than
 * creating the space for each one. As a result, one could obtain the constant
 * space complexity O(1)\mathcal{O}(1)O(1) for the overhead of the recursive
 * calls.
 */
class Solution {
 public:
  queue<pair<TreeNode*, int>> next;
  int ans = INT_MIN;
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    next.push(make_pair(root, 1));
    tail_recursion();
    return ans;
  }
  void tail_recursion() {
    if (next.empty()) return;

    pair<TreeNode*, int> ele = next.front();
    next.pop();
    TreeNode* node = ele.first;
    int level = ele.second;
    ans = max(ans, level);

    if (node->left) next.push({node->left, level + 1});
    if (node->right) next.push({node->right, level + 1});
    tail_recursion();
  }
};
