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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if(!root) return result;
        bool inverse=false;

        std::queue<TreeNode*> node_queue;
        node_queue.push(root);
        while(!node_queue.empty()){
            int level_size = node_queue.size();
            std::vector<int> level;
            for (int i=0; i<level_size; ++i){
                TreeNode* node = node_queue.front();
                node_queue.pop();
                level.push_back(node->val);
                if(node->left) node_queue.push(node->left);
                if(node->right) node_queue.push(node->right);
            }
            if(inverse) std::reverse(level.begin(),level.end());
            result.push_back(level);
            inverse = !inverse;
        }
        return result;
    }
};
