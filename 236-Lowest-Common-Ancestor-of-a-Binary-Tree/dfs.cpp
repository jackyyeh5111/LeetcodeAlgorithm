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
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        dfs(root, p, q);
        return ans;
    }
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return false;
        if (ans) // early stop
            return ans;
        
        bool in_left = dfs(root->left, p, q);
        bool in_right = dfs(root->right, p, q);
        bool in_self = root->val == p->val || root->val == q->val;
        bool found = (in_left && in_right) || (in_right && in_self) || (in_left && in_self);
        if (found && !ans)
            ans = root;
        return in_left || in_right || in_self;
    }
};