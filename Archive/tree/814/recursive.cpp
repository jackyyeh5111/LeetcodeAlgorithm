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
    TreeNode* pruneTree(TreeNode* root)
    {
        if (!root) return root;
        if (containOne(root)) return root;
        else return NULL;
    }

    bool containOne(TreeNode* node)
    {
        if (!node) return false;

        bool left = containOne(node->left);
        if (!left) node->left = NULL;
        bool right = containOne(node->right);
        if (!right) node->right = NULL;
        return (node->val == 1) || left || right;
    }
    /*
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->left == NULL && root->right==NULL && root->val==0) return NULL;
        return root;
    }
    */
};
