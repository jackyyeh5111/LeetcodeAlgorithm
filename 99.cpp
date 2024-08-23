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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> sort_arr;
        inorder(root, sort_arr);

        // recover
        TreeNode *wrong1 = nullptr;
        TreeNode *wrong2 = nullptr;
        for (int i = 0; i < sort_arr.size() - 1; i++) {
            if (sort_arr[i]->val > sort_arr[i+1]->val) {
                // first wrong node
                if (!wrong1)
                    wrong1 = sort_arr[i];
                
                // consider edge case (when two wrong nodes are adjcent)
                wrong2 = sort_arr[i+1];
            }
        }
        
        swap(wrong1->val, wrong2->val);
    }
    void inorder(TreeNode* root, vector<TreeNode*> &sort_arr) {
        if (!root)
            return;
        inorder(root->left, sort_arr);
        sort_arr.push_back(root);
        inorder(root->right, sort_arr);
    }
};