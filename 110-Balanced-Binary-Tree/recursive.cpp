/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 
  Time: O(n)
 */
class Solution2 {
public:
    bool is_balanced = true;
    bool isBalanced(TreeNode* root) {
        checkHeight(root);
        return is_balanced;
    }
    int checkHeight(TreeNode* root) {
        if (!root)
            return 0;
        if (is_balanced == false)
            return 0;
        int left_height = checkHeight(root->left);
        int right_height = checkHeight(root->right);
        if (abs(left_height - right_height) > 1)
            is_balanced = false;
        return max(left_height, right_height) + 1;
    }
};

/* 
    Time: O(n^2)
 */
class Solution1 {
private:
    // Recursively obtain the height of a tree. An empty tree has -1 height
    int height(TreeNode* root) {
        // An empty tree has height -1
        if (root == NULL) {
            return -1;
        }
        return 1 + max(height(root->left), height(root->right));
    }

public:
    bool isBalanced(TreeNode* root) {
        // An empty tree satisfies the definition of a balanced tree
        if (root == NULL) {
            return true;
        }

        // Check if subtrees have height within 1. If they do, check if the
        // subtrees are balanced
        return abs(height(root->left) - height(root->right)) < 2 &&
               isBalanced(root->left) && isBalanced(root->right);
    }
};