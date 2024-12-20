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
 */
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return nullptr;
        if (!root->left) return root; // Y
        TreeNode* new_root = upsideDownBinaryTree(root->left); // new_root: Y
        root->left->left = root->right;
        root->left->right = root;
        root->left = nullptr; // do not forget to handle the last node
        root->right = nullptr; // do not forget to handle the last node
        return new_root;
    }
};