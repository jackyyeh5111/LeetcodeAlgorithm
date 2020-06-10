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
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root) return {{}};
        int tree_height = getHeight(root);
        vector<vector<string>> result;
        for(int i=0; i<tree_height; ++i){
            vector<string> level((1<<tree_height)-1,"");
            result.push_back(level);
        }
        if(tree_height==1) {
            result[0][0]=to_string(root->val);
        }


        queue<TreeNode*> record;
        record.push(root);
        int level = 0;
        while(record.size() < ((1<<tree_height)-1)){
            int level_size = record.size();
            for(int i=0; i<level_size; ++i) {
                TreeNode* node = record.front();
                record.pop();
                string val="";
                if(node) val = std::to_string(node->val);
                result[level][(1<<(tree_height-level-1))-1+i*(1<<(tree_height-level))]=val;
                if(!node){
                    record.push(0);
                    record.push(0);
                }
                else {
                    record.push(node->left);
                    record.push(node->right);
                }
            }
            level++;
        }
        return result;
    }

    int getHeight(TreeNode* node){
        if(!node) return 0;
        return max(getHeight(node->left),getHeight(node->right))+1;
    }
};
