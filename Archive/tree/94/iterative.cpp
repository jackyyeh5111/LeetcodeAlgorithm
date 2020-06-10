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
    /*
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        std::stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            TreeNode* node = node_stack.top();
            node_stack.pop();

            if (node->right) {
                node_stack.push(node->right);
                node->right = NULL;
            }
            if (!node->left) {
                result.push_back(node->val);
            } else {
                node_stack.push(node);
            }
            if (node->left) {
                node_stack.push(node->left);
                node->left = NULL;
            }
        }

        return result;
    }
    */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        std::stack<TreeNode*> node_stack;

        while (root || !node_stack.empty()) {

            if (root) {
                node_stack.push(root);
                root = root->left;
            }
            else {
                root = node_stack.top();
                node_stack.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }

        return result;
    }
};
