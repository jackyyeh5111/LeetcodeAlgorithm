
/*
    Think about the information we'd like to carry on while backtracking
    For each node, return its dpeth with its node ptr, i.e. <TreeNode*,int>
    While backtracking, compare left&right inform, if they have same depth, then we should choose the current node which containts all largest depth tree.
    Else return the larger one.
	T:O(n)/S:O(n)
*/
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        return root?postOrder(root,0).first:0;
    }

    pair<TreeNode*,int> postOrder(TreeNode* root, int d)
    {
        pair<TreeNode*,int> left={root,d}, right={root,d};
        if (root->left) left=postOrder(root->left,d+1);
        if (root->right) right=postOrder(root->right,d+1);
        if (left.second==right.second) return {root,left.second};
        else if (left.second>right.second) return left;
        else return right;
    }
};
