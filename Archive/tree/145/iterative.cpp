/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        if (!root) return result;
        std::stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            TreeNode* node = node_stack.top();
            if (!node->left && !node->right) {
                result.push_back(node->val);
                node_stack.pop();
            }
            if (node->right) {
                node_stack.push(node->right);
                node->right = NULL;
            }
            if (node->left) {
                node_stack.push(node->left);
                node->left = NULL;
            }
        }
        return result;
    }
    /*
    vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        if (!root) return result;
        std::stack<TreeNode*> node_stack;
        TreeNode* predecessar=nullptr;
        while (root || !node_stack.empty()) {
            if (root) {
                node_stack.push(root);
                root = root->left;
            }
            else {
                TreeNode* node = node_stack.top();
                if (node->right && node->right != predecessar) {
                    root = node->right;
                }
                else {
                    result.push_back(node->val);
                    node_stack.pop();
                    predecessar = node;
                }

            }
        }
        return result;
    }
    */
};
