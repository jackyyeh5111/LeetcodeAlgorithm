/***** Second Visit *****/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        postOrder(root,ans);
        return ans;
    }

    int postOrder(TreeNode *root, int &ans)
    {
        if (!root) return -1;
        else if (!root->left&&!root->right) return 0;
        int left=postOrder(root->left,ans);
        int right=postOrder(root->right,ans);
        ans=max(ans,left+right+2);
        return max(left,right)+1;
    }
};

/***** First Visit *****/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        int ans=0;
        dfs(root,ans);
        return ans>0?ans-1:0;
    }

    int dfs(TreeNode *root, int &ans)
    {
        if (!root) return 0;
        int l=dfs(root->left,ans);
        int r=dfs(root->right,ans);
        ans=max(ans,l+r+1);
        return max(l,r)+1;
    }
};
