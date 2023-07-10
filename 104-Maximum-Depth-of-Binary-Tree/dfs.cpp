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
    int max_depth = 0;
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return max_depth;
    }
    void dfs(TreeNode* node, int depth) {
        if (!node)
            return;
        ++depth;
        max_depth = max(max_depth, depth);
        dfs(node->left, depth);
        dfs(node->right, depth);
    }
};