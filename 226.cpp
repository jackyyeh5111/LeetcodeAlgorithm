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
/********** recursive **********/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root) return 0;
        TreeNode *left=invertTree(root->left);
        TreeNode *right=invertTree(root->right);
        root->left=right; root->right=left;
        return root;
    }
};

/********** iterative **********/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        stack<TreeNode*> s;
        if (root) s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top(); s.pop();
            TreeNode *left=node->left;
            TreeNode *right=node->right;
            node->left=right;
            node->right=left;
            if (left) s.push(left);
            if (right) s.push(right);
        }
        return root;
    }
};
