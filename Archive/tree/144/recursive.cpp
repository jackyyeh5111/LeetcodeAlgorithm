/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<stack>
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        traverse(root, result);
        return result;
    }

    void traverse(TreeNode* node, vector<int>& result)
    {
        result.push_back(node->val);
        if (node->left) traverse(node->left, result);
        if (node->right) traverse(node->right, result);
    }
};
