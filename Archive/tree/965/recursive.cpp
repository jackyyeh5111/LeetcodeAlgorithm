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
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        bool result=true;
        bool left=true; bool right=true;
        if(root->left) {
            result = result&&(root->val==root->left->val);
            left=isUnivalTree(root->left);
        }
        if(root->right) {
            result = result&&(root->val==root->right->val);
            right=isUnivalTree(root->right);
        }
        return result&&left&&right;

    }
};
