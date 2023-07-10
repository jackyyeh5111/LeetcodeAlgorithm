/* Top-down */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

/* Bottom-up */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;
        TreeNode* tmp = invertTree(root->right);
        root->right = invertTree(root->left);
        root->left = tmp;
        return root;
    }
};