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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        traverse(root, result);
        return result;
    }

    void traverse(TreeNode* node, vector<int>& result)
    {
        if (!node->left && !node->right) {
            result.push_back(node->val);
            return;
        }
        if (!node->left)
            traverse(node->left, result);
        result.push_back(node->val);
        if (!node->right)
            traverse(node->right, result);
    }
};
