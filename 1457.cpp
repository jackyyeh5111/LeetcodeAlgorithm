/*
    prreorder + bit manipulation
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root)
    {
        int ans=0, cache=0;
        dfs(root,cache,ans);
        return ans;
    }

    void dfs(TreeNode *root, int &cache, int &ans)
    {
        if (!root) return;
        cache^=(1<<root->val);
        if (!root->left&&!root->right) {
            // check
            if (cache==0||((cache&(cache-1))==0)) ans++;
        }
        else {
            if (root->left) dfs(root->left,cache,ans);
            if (root->right) dfs(root->right,cache,ans);
        }
        cache^=(1<<root->val);
    }
};
