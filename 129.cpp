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
 // T:O(n), S:O(logN)
class Solution {
public:
    int sum=0;
    int sumNumbers(TreeNode* root)
    {
        help(root,0);
        return sum;
    }

    void help(TreeNode *root, int val)
    {
        if (!root) return;
        val=val*10+root->val;
        if(!root->left&&!root->right) sum+=val;
        else {
            help(root->left,val);
            help(root->right,val);
        }
    }
};
