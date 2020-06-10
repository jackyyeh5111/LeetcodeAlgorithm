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
    void flatten(TreeNode* root) {
        if(!root) return;

        if(root->right) flatten(root->right);
        if(root->left) flatten(root->left);
        if(!root->right && !root->left) return;
        if(root->left) {
            TreeNode* right=root->right;
            root->right=root->left;
            root->left=0;
            while(root->right) root=root->right;
            root->right=right;
        }


    }
};
