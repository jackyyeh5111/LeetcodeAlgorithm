/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root) return 0;
        int value = root->val;
        int right=0; int left=0;
        if(value>=R) {
            left=rangeSumBST(root->left,L,R);
        }
        else if(value<=L) {
            right=rangeSumBST(root->right,L,R);
        }
        else{
            left=rangeSumBST(root->left,L,R);
            right=rangeSumBST(root->right,L,R);
        }
        if(value<L||value>R) value=0;
        return value+left+right;
    }
};
