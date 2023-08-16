/* 
    Wrong answer

    Fail case:
        root: [2147483647]
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, INT_MIN, INT_MAX);
    }

    bool validate(TreeNode* root, int low, int high) {
        if (!root)
            return true;
        if (root->val <= low || root->val >= high)
            return false;
        return validate(root->left, low, root->val) && validate(root->right, root->val, high);
    }
};