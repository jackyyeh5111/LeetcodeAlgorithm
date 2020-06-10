/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y)
    {
        std::queue<TreeNode*> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            TreeNode* node = node_queue.top();
            node_queue.pop();

            if (x == node->value)

            if (node->left) node_queue.push(node->left);
            if (node->right) node_queue.push(node->right);
        }
        return result;
    }
};
