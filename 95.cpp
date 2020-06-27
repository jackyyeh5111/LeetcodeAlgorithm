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
    vector<TreeNode*> generateTrees(int n)
    {
        /*
            Catalan Number again
            combinations: 1/(n+1) C^2n_n

            recursive may cause TLE, use DP.
            B2=B0B1+B1B0
            B3=B0B2+B1B1+B2B0
            B4=B0B3+B1B2+B2B1+B3B0
        */
        if (n==0) return vector<TreeNode*>{};
        vector<vector<TreeNode*>> dp(n+1,vector<TreeNode*>{});
        dp[0].push_back(0);
        dp[1].push_back(new TreeNode(1));
        for (int i=2; i<=n; ++i) {
            vector<TreeNode*> tmp;
            for (int j=0; j<i; ++j) {
                vector<TreeNode*> lefts=dp[j];
                vector<TreeNode*> rights=dp[i-1-j];
                for (auto left:lefts) {
                    for (auto right: rights) {
                        TreeNode* root=new TreeNode(i);
                        root->left=left;
                        root->right=right;
                        tmp.push_back(root);
                    }
                }
            }
            dp[i]=tmp;
        }
        for (auto &tree: dp[n]) {
            int start=1;
            tree = fillBST(tree, start);
        }
        return dp[n];
    }

    TreeNode* fillBST(TreeNode *root, int &val)
    {
        if (!root) return 0;
        TreeNode *new_root=new TreeNode(0);
        if (root->left) new_root->left=fillBST(root->left, val);
        new_root->val=val++;
        if (root->right) new_root->right=fillBST(root->right, val);
        return new_root;
    }
};
