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
     // iterative T:O(n), S:O(n)
     vector<int> ans;
     vector<int> inorderTraversal(TreeNode* root) {
         stack<pair<TreeNode*,bool>> s;
         if (root) s.push(make_pair(root,false));
         while(!s.empty()){
             auto p=s.top(); s.pop();
             if (p.second) ans.push_back(p.first->val);
             else {
                 if (p.first->right) s.push(make_pair(p.first->right,false));
                 p.second=true; s.push(p);
                 if (p.first->left) s.push(make_pair(p.first->left,false));
             }
         }
         return ans;
     }
 };

class Solution {
public:
    // recursive T:O(n), S:O(logn) average height
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* root)
    {
        if (!root) return;
        if (root->left) inorder(root->left);
        ans.push_back(root->val);
        if (root->right) inorder(root->right);
    }
};
