/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return root;
        TreeNode* result = rearange(root);
        return result;
    }

    TreeNode* rearange(TreeNode* node)
    {
        if (!node) return NULL;
        TreeNode* left = rearange(node->left);
        TreeNode* right = rearange(node->right);
        node->left = NULL;
        if (right) node->right = right;
        if (left) {
            TreeNode* root = left;
            while (left->right) left = left->right;
            left->right = node;
            return root;
        }
        else {
            return node;
        }

    }
};
