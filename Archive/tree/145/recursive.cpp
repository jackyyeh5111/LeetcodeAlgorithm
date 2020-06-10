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
    vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        if (!root) return result;
        traverse(root, result);
        return result;
    }

    void traverse(TreeNode* node, vector<int>& result)
    {
        if (node->left) traverse(node->left, result);
        if (node->right) traverse(node->right, result);
        result.push_back(node->val);
    }
};
