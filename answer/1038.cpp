class Solution {
public:
    TreeNode* bstToGst(TreeNode* root)
    {
        int csum=0;
        help(root,csum);
        return root;
    }

    void help(TreeNode *root, int &csum)
    {
        if (!root) return;
        help(root->right,csum);
        csum+=root->val;
        root->val=csum;
        help(root->left,csum);
    }
};
