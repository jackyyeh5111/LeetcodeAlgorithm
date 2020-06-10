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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> sequence1; preOrder(root1, sequence1);
        vector<int> sequence2; preOrder(root2, sequence2);
        return sequence1==sequence2;
    }

    void preOrder(TreeNode* node, vector<int>& sequence){
        if(!node) return;
        if(node->left) preOrder(node->left, sequence);
        if(!node->left&&!node->right) sequence.push_back(node->val);
        if(node->right) preOrder(node->right, sequence);
    }
};
