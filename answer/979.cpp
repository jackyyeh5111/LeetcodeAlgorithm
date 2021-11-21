/*
    postorder
    T:O(n)/S:O(nn)
*/
class Solution {
public:
    // return total moves
    int distributeCoins(TreeNode* root)
    {
        int ans=0;
        postOrder(root, ans);
        return ans;
    }

    // return the coins it need(-) or provide(+)
    int postOrder(TreeNode *root, int &ans)
    {
        if (!root) return 0;
        int left=postOrder(root->left, ans);
        int right=postOrder(root->right, ans);
        ans+=(abs(left)+abs(right));
        int ret=root->val - 1 + left + right;
        return ret;
    }
};
