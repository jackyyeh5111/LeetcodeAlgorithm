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
    bool isCousins(TreeNode* root, int x, int y)
    {
        bool result = false;
        int x_d = -1; int y_d = -1; int k = 0;
        int parent_x, parent_y, parent;
        parent_x = -1;
        parent_y = -1;
        parent=root->val;
        traverse (root, x, y, x_d, y_d, result, k, parent_x, parent_y, parent);
        return result;
    }

    void traverse(TreeNode* node, int x, int y, int& x_d, int& y_d,
                  bool& result, int k, int& parent_x, int& parent_y, int parent)
    {
        if (!node) return;

        if (node->val == x) { x_d = k; parent_x = parent; }
        if (node->val == y) { y_d = k; parent_y = parent; }
        if (x_d != -1 && y_d != -1){
            if (x_d == y_d && parent_x != parent_y) result = true;
            else result = false;
            return;
        }
        k = k + 1;
        traverse(node->left, x, y, x_d, y_d, result, k, parent_x, parent_y, node->val);
        traverse(node->right, x, y, x_d, y_d, result, k, parent_x, parent_y, node->val);
    }
};
