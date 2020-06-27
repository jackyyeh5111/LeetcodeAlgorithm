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
    int countNodes(TreeNode* root)
    {
        /*
            if (0) return 0
            count
            if (left) count+=countNodes(left)
            if (right) count+=countNodes(right)
            -----------------
            recursive preorder/inorder/postorder, T:O(n), S:O(logn) in average
            recursive interms of DEPTH:
            T(n)=T(n/2)+2*logn
            -> master theorem case 3: O((logn)^2)
        */

        if(!root) return 0;
        int leftD=getDepth(root->left);
        int rightD=getDepth(root->right);
        if (leftD==rightD)
            return (1<<leftD)+countNodes(root->right);
        else
            return (1<<rightD)+countNodes(root->left);
    }

    int getDepth(TreeNode *root)
    {
        if (!root) return 0;
        return 1+getDepth(root->left);
    }
};
