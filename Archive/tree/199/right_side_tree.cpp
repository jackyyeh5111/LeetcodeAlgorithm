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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> record;
        record.push(root);
        while(!record.empty()){
            int size = record.size();
            for(int i=0; i<size-1; ++i){
                TreeNode* node = record.front();
                record.pop();
                if(node->left) record.push(node->left);
                if(node->right) record.push(node->right);
            }
            TreeNode* node = record.front();
            record.pop();
            if(node->left) record.push(node->left);
            if(node->right) record.push(node->right);
            result.push_back(node->val);
        }
        return result;
    }
};
