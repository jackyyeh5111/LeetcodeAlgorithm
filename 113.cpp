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
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        /*
            ALL root-to-leaf -> accept duplicated path
            Use root first traversall, i.e. NLR || level order.
            if leaf, check sum, if sum==root->val then return path.
            We may need a help function for recording current path.
            T:O(n), S:O(logn)
        */
        vector<int> path{};
        help(root, sum, path);
        return ans;
    }

    void help(TreeNode* root, int sum, vector<int>& path)
    {
        if (!root) return;
        path.push_back(root->val); // visit
        if(!root->left&&!root->right&&sum==root->val) ans.push_back(path);
        help(root->left, sum-root->val, path);
        help(root->right, sum-root->val, path);
        path.pop_back();
    }
};
