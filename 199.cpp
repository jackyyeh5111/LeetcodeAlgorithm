/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/************************* NRL traversal *************************/
class Solution {
public:
    //T:O(n), S:O(n)
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        help(root,0);
        return ans;
    }

    void help(TreeNode* root, int level)
    {
        if (!root) return;
        if (ans.size()<=level) ans.push_back(root->val);
        help(root->right,level+1);
        help(root->left,level+1);
    }
};

/************************* levelorder traversal *************************/
class Solution {
public:
    //T:O(n), S:O(n)
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root) q.push(root);
        while(!q.empty()) {
            int size=q.size();
            for (int i=0;i<size;++i){
                TreeNode* node=q.front(); q.pop();
                if(i==size-1) ans.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return ans;
     }
};
