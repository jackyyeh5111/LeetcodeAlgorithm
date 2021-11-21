/*
    preorder
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int maxProduct(TreeNode* root)
    {
        long ans=0;
        if (root) {
            auto total=count(root);
            help(root,total.first,total.second, ans);
            ans=ans%((int)pow(10,9)+7);
        }
        return ans;
    }

    // <# of nodes, sum>
    pair<int,long> count(TreeNode *root)
    {
        if (!root) return {0,0};
        auto l=count(root->left);
        auto r=count(root->right);
        return {l.first+r.first+1,l.second+r.second+root->val};
    }

    // <# of nodes, sum>
    pair<int,long> help(TreeNode *root, int tnodes, long sum, long &ans)
    {
        if (!root) return {0,0};
        auto l=help(root->left,tnodes,sum,ans);
        auto r=help(root->right,tnodes,sum,ans);
        pair<int,long> ret{l.first+r.first+1,l.second+r.second+root->val};
        ans=max(ans,ret.second*(sum-ret.second));
        return ret;
    }
};
