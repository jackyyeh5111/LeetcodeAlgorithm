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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* node = root;
        vector<int> ans;
        while(node || !stk.empty()) {
            if (node) {
                stk.push(node);
                node = node->left;
            }
            else {
                node = stk.top();
                ans.push_back(node->val);
                node = node->right;  // Add after all left children
                stk.pop();
            }
        }

        return ans;
        
    }
};