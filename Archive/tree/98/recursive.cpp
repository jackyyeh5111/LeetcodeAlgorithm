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
    bool isValidBST(TreeNode* root) {
        // iterative approach
        return dfs(root, nullptr, nullptr);
    }
    bool dfs(TreeNode* node, TreeNode* low, TreeNode* high) {
        if (!node) return true;
        if (low && node->val <= low->val) return false;
        if (high && node->val >= high->val) return false;
        return dfs(node->left, low, node) && dfs(node->right, node, high);
    }
};

/* 

                       [6] (#, #)
                /              \
             [2] (#, 6)          [8] (6, #)
           /     \             /     \
        [0]       [4]       [7] (6, 8)    [9] (8, #)   

 */