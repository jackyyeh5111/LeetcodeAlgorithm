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
    bool ans=true;
    bool isBalanced(TreeNode* root)
    {
        getDepth(root);
        return ans;
    }

    int getDepth(TreeNode *root)
    {
        if(!root) return 0;
        int left=getDepth(root->left);
        int right=getDepth(root->right);
        if (abs(right-left)>1) { ans=false; return -1; }
        else return max(left,right)+1;
    }
};
