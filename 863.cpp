/*
    DFS+postDFS
    dfs to find target node and further count the K distant nodes.
    postDFS to find parent/grandparent and siblings candidates.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
    {
         vector<int> ans;
         dfs(root,K,target,ans);
         return ans;
    }

    bool dfs(TreeNode *root, int &K, TreeNode*target, vector<int> &ans)
    {
        bool found=false;
        if (!root) return found;
        if (root==target) {
            help(root,K,ans);
            K--;
            return true;
        }
        if (dfs(root->left,K,target,ans)) {
            help(root->right,K-1,ans);
            found=true;
        }
        else if (dfs(root->right,K,target,ans)) {
             help(root->left,K-1,ans);
             found=true;
        }
        if (found&&K==0) ans.push_back(root->val);
        if (found) K--;
        return found;
    }

    void help(TreeNode *root, int K, vector<int> &ans)
    {
        if (!root||K<0) return;
        if (K==0) ans.push_back(root->val);
        help(root->left, K-1, ans);
        help(root->right, K-1, ans);
    }
};
