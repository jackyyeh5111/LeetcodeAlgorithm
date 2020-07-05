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
    int minDepth(TreeNode* root)
    {
        /*
            find the min path from root to leaf
            just use DFS traverse and check minDepth instead of maxDepth
            Note: A leaf is a node with NO children.
            T:O(n), S:O(logn)
            ------------------------
            We can use queue for an iterative approach and early stop while we
            first meet the node with no children.
        */
        if(!root) return 0;
        if(!root->left&&!root->right) return 1;
        int left=INT_MAX,right=INT_MAX;
        if(root->left) left=minDepth(root->left);
        if(root->right) right=minDepth(root->right);
        return min(left,right)+1;
    }
};
