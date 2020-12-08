/*
    level order traversal
    T:O(n)/S:O(n)
*/
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        queue<TreeNode*> q;
        TreeNode *header=new TreeNode();
        header->left=root;
        q.push(header);
        for (int i=0; i<d-1; ++i) {
            int k=q.size();
            for (int j=0; j<k; ++j) {
                TreeNode *node=q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        while (!q.empty()) {
            TreeNode *node=q.front(); q.pop();
            TreeNode *left=node->left, *right=node->right;
            node->left=new TreeNode(v);
            node->left->left=left;
            node->right=new TreeNode(v);
            node->right->right=right;
        }
        return header->left;
    }
};
