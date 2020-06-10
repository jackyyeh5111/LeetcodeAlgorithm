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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> record;
        record.push(root);
        while(true){
            TreeNode* node = record.front();
            record.pop();
            if(!node){
                while(!record.empty()){
                    TreeNode* leaf = record.front();
                    record.pop();
                    if(leaf) return false;
                }
                return true;
            }
            record.push(node->left);
            record.push(node->right);
        }
    }
};
