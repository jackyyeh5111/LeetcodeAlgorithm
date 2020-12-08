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
/*
    Sum of all path in binary
    Top down(NLR) or bottom up(LNR) recursive ?
    Bottom up: need to explicity tell the length
    Top down: directly << 1 recursively, don't even know what's the length now.
    T:O(n)/S:O(n)
    To reduct space complexity, change it to morris traversal:
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int sumRootToLeaf(TreeNode* root)
    {
        int cur=0,ans=0;
        help(root,cur,ans);
        return ans;
    }

    void help(TreeNode* root, int cur, int& ans)
    {
        if (!root) return;
        cur=(cur<<1)+root->val;
        if (!root->left&&!root->right) ans+=cur;
        else {
            help(root->left,cur,ans);
            help(root->right,cur,ans);
        }
    }
};
