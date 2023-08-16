class Solution {
public:
    TreeNode* prev = nullptr;
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (prev && prev->val >= root->val)
            return false;
        prev = root;
        if (!isValidBST(root->right))
            return false;
        
        return true;
    }
};