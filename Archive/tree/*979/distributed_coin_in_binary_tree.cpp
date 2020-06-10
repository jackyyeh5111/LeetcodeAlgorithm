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
    int moves;
    int distributeCoins(TreeNode* root) {
        moves = 0;
        traverse(root);
        return moves;
    }

    int traverse(TreeNode* node) {
        if(!node) return 0;
        int left = traverse(node->left);
        int right = traverse(node->right);
        moves += (abs(left) + abs(right));
        return node->val + left + right - 1;
    }
};
