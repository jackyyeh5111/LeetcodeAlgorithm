/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int* predVal = 0;

    bool isValidBST(TreeNode* root)
    {
        if (!root) return true;
        return inorderCheck(root);
    }

    bool inorderCheck(TreeNode* root)
    {
        if (!root) return true;
        bool left = inorderCheck(root->left);
        if (predVal && root->val <= *predVal) return false;
        predVal = &(root->val);
        bool right = inorderCheck(root->right);

        return left && right;
    }
};
