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
/*
    delete a node in BST
    1. search node, notice duplicate case O(logn)
    2. delete the node. 3 cases
        1. the node is leaf
        2. if the node has only left/right node, replace by its child
        3. if the node has both left/right child, replace by its predecessor or successor
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        TreeNode *cur=root, *prev=0;
        bool left;
        while(cur&&cur->val!=key) {
            prev=cur;
            if (cur->val>key) {left=1; cur=cur->left;}
            else {left=0; cur=cur->right;}
        }
        if (!cur) return root;
        TreeNode *target=deleteTarget(cur);
        if (!prev) return target;
        else if (left) prev->left=target;
        else prev->right=target;
        return root;
    }

    TreeNode* deleteTarget(TreeNode *node)
    {
        if (!node->left&&!node->right) {delete node; return 0;}
        else if (!node->left||!node->right) {
            TreeNode *child=node->left?node->left:node->right;
            delete node;
            return child;
        }
        else {
            TreeNode *suc=node->right, *prev=node;
            while(suc->left) {prev=suc; suc=suc->left;}
            if (prev!=node) {
                prev->left=suc->right;
                suc->right=node->right;
            }
            suc->left=node->left;
            return suc;
        }
    }
};
