/*
    preorder
    T:O(n)/S:O(n)
*/
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if (target==original) return cloned;
        else if (!original|!cloned) return 0;
        TreeNode *left=getTargetCopy(original->left,cloned->left,target);
        TreeNode *right=getTargetCopy(original->right,cloned->right,target);
        return left?left:right;
    }
};
