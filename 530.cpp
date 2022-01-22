#include "utils.hpp"

class Solution3 {
 public:
  int getMinimumDifference(TreeNode* root) {
    inorder(root);
    return min_diff;
  }

 private:
  void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);
    if (prev) min_diff = min(min_diff, root->val - prev->val);
    prev = root;
    inorder(root->right);
  }

  TreeNode* prev = nullptr;
  int min_diff = INT_MAX;
};

/* 這解法有錯！
    prev pointer 會被複製很多遍
 */
class Solution2 {
 public:
  int getMinimumDifference(TreeNode* root) {
    inorder(root, nullptr);
    return min_diff;
  }

 private:
  void inorder(TreeNode* root, TreeNode* prev) {
    if (!root) return;

    inorder(root->left, prev);
    if (prev) min_diff = min(min_diff, root->val - prev->val);
    prev = root;
    inorder(root->right, prev);
  }

  int min_diff = INT_MAX;
};

/*
   這解法是錯的！ 此解法預設相差最小的兩個節點必定相鄰，但 BST 有可能會分開(如
   test case 2)。
   還是必須要紀錄前一個訪問的節點才行
 */
class Solution {
 public:
  int getMinimumDifference(TreeNode* root) {
    int min_diff = INT_MAX;
    inorder(root, min_diff);
    return min_diff;
  }

  void inorder(TreeNode* root, int& min_diff) {
    if (root->left) {
      inorder(root->left, min_diff);
      min_diff = min(min_diff, root->val - root->left->val);
    }
    if (root->right) {
      inorder(root->right, min_diff);
      min_diff = min(min_diff, root->right->val - root->val);
    }
  }
};

int main(int argc, char** argv) {
  // test case 1
  //   vector<TreeNode*> vals{new TreeNode(4), new TreeNode(2), new TreeNode(6),
  //                          new TreeNode(1), new TreeNode(3)};
  //   TreeNode* root = initTreeNodes(vals);

  Solution2 sol;
  //   int ans = sol.getMinimumDifference(root);
  //   std::cout << "ans: " << ans << '\n';

  // test case 2
  vector<TreeNode*> vals2{
      new TreeNode(236), new TreeNode(104), new TreeNode(701), nullptr,
      new TreeNode(227), nullptr,           new TreeNode(911)};

  TreeNode* root = initTreeNodes(vals2);
  int ans = sol.getMinimumDifference(root);
  std::cout << "ans: " << ans << '\n';

  return 0;
}