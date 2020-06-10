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
    /*
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> node_stack;
        while (root || !node_stack.empty()) {
            if (root) {
                result.push_back(root->val);
                node_stack.push(root->right);
                root = root->left;
            }
            else {
                root = node_stack.top();
                node_stack.pop();
            }
        }
        return result;
    }
    */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            TreeNode* node = node_stack.top();
            node_stack.pop();

            result.push_back(node->val);
            if (node->right)
                node_stack.push(node->right);
            if (node->left)
                node_stack.push(node->left);
        }
        return result;
    }
};
