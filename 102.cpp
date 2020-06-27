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
    While having level order, we just need to ensure one thing:
        The root node is traced before all its child node.
    Thus, we can adopt queue for iteration and preorder(NLR) for recursive.
 */

/************* Queue ************/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        /*
            tree level order: QUEUE!
            T:O(n), S:O(n)
        */
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while(!q.empty()) {
            int size=q.size();
            vector<int> level;
            for(int i=0; i<size; ++i){
                TreeNode *node=q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

/************* preorder traversal ************/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        help(root, 0);
        return ans;
    }

    void help(TreeNode *root, int depth)
    {
        if(!root) return;
        if(depth==ans.size())
            ans.push_back(vector<int>{});
        ans[depth].push_back(root->val);
        help(root->left, depth+1);
        help(root->right, depth+1);
    }
};
