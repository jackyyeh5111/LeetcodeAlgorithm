/*
    Post order traversal
    T:O(n)/S:O(n)
*/
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if (!root) return 0;
        else if (root->val<low) return trimBST(root->right,low,high);
        else if (root->val>high) return trimBST(root->left,low,high);
        root->left=trimBST(root->left,low,high);
        root->right=trimBST(root->right,low,high);
        return root;
    }
};
