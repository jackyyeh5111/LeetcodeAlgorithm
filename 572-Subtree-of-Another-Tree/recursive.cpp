class Solution2 {
 public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root || !subRoot) return root == subRoot;
    if (isSame(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
  bool isSame(TreeNode* root, TreeNode* subRoot) {
    if (!root || !subRoot) return root == subRoot;
    if (root->val != subRoot->val) return false;
    return isSame(root->left, subRoot->left) &&
           isSame(root->right, subRoot->right);
  }
};

/*
     Wrong answer

    Fail case:
           root = [1, 1]
        subRoot = [1]
 */
class Solution {
 public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root && !subRoot) return true;
    if (!root && subRoot) return false;
    if (root && !subRoot) return false;

    if (root->val != subRoot->val) {
      return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    return isSubtree(root->left, subRoot->left) &&
           isSubtree(root->right, subRoot->right);
  }
};
