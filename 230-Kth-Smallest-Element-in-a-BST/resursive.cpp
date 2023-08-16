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
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
    int order = 0;
    int inorder(TreeNode* node, int k) {
        if (!node)
            return -1; // dummy
        int val = inorder(node->left, k);
        if (val != -1)
            return val;
        order++;
        if (order == k)
            return node->val;
        val = inorder(node->right, k);
        if (val != -1)
            return val;
        return -1;
    }
};

/* 
        2
      /
    1
    
 */



