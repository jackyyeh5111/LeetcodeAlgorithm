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
        stack<vector<TreeNode*>> stk; // {node, low, high}
        stk.push({root, nullptr, nullptr});

        // must use stack for in-order traversal
        while(!stk.empty()) {
            TreeNode* node = stk.top()[0];
            TreeNode* low = stk.top()[1];
            TreeNode* high = stk.top()[2];
            stk.pop();

            if (low && low->val >= node->val)
                return false;
            if (high && high->val <= node->val)
                return false;

            if (node->right)
                stk.push({node->right, node, high});
            if (node->left)
                stk.push({node->left, low, node});
        }
        return true;
    }
};
