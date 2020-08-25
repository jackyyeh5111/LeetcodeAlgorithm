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
    Use NLR traversal to iterate over each node then add left node to sum.
    Note that we are asked to get sum of LEAF, not all left nodes!
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        preorder(root,sum,false);
        return sum;
    }

    void preorder(TreeNode *root, int &sum, bool isLeft)
    {
        if (!root) return;
        if (!root->left&&!root->right&&isLeft) sum+=root->val;
        preorder(root->left,sum,true);
        preorder(root->right,sum,false);
    }
};
