/*
    preorder traversal
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int goodNodes(TreeNode* root)
    {
        int ans=0;
        if (root) help(root,INT_MIN,ans);
        return ans;
    }

    void help(TreeNode *root, int cur_max, int &ans)
    {
        if (!root) return;
        cur_max=max(cur_max,root->val);
        if (cur_max<=root->val) ans++;
        help(root->left,cur_max,ans);
        help(root->right,cur_max,ans);
    }
};
