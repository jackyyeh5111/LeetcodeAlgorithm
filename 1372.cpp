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
 // Post-order traversal, T:O(n)
class Solution {
public:
    int ans = 0;
    int longestZigZag(TreeNode* root) {
        help(root);
        return max(0,ans-1);
    }

    pair<int,int> help(TreeNode* root)
    {
        if (!root) return make_pair(0,0); //left, right
        auto left = help(root->left);
        auto right = help(root->right);
        ans=max(ans,max(right.first, left.second)+1);
        return make_pair(left.second+1, right.first+1);
    }
};
