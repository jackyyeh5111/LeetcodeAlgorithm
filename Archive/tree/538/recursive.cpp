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
    /*
    TreeNode* convertBST(TreeNode* root)
    {
        if (!root) return root;
        int preVal = 0;
        traverse(root, preVal);
        return root;
    }

    void traverse(TreeNode* node ,int& preVal)
    {
        if (!node) return;
        traverse(node->right, preVal);
        node->val += preVal;
        preVal = node->val;
        traverse(node->left, preVal);
    }
    */
    TreeNode* convertBST(TreeNode* root)
    {
        if (!root) return root;
        TreeNode* pre = 0;
        traverse(root, &pre);
        return root;
    }

    void traverse(TreeNode* node ,TreeNode** pre)
    {
        if (!node) return;
        traverse(node->right, pre);
        if (*pre) node->val += (*pre)->val;
        *pre = node;
        traverse(node->left, pre);
    }

    // HOW ABOUT USING RECURSIVE TO RECORD PREDECESSOR
};
