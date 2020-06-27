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

/****************** level order traversal via queue *********************/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool fromLeft=false;
        if (root) q.push(root);
        while (!q.empty()) {
            int size=q.size();
            vector<int> level;
            for (int i=0; i<size; ++i) {
                TreeNode *node=q.front(); q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(fromLeft) reverse(level.begin(), level.end());
            ans.push_back(level);
            fromLeft=!fromLeft;
        }
        return ans;
    }
};

/****************** Preorder traversal *********************/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        help(root, 0);
        return ans;
    }

    void help(TreeNode* root, int depth)
    {
        if(!root) return;
        if (depth==ans.size())
            ans.push_back(vector<int>{});

        if (depth%2==0) ans[depth].push_back(root->val);
        else ans[depth].insert(ans[depth].begin(), root->val);
        help(root->left, depth+1);
        help(root->right, depth+1);
    }
};
