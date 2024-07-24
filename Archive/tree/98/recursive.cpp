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
    TreeNode* pre_node = nullptr;
    bool isValidBST(TreeNode* root) {
        // inorder traversal to check
        if (!root)
            return true;

        if (!isValidBST(root->left))
            return false;
        
        if (pre_node && pre_node->val >= root->val)
            return false;
        
        pre_node = root;
        if (!isValidBST(root->right))
            return false;
        
        return true;
    }
};