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
    vector<pair<TreeNode*, int>> levels;
    int idx_p = -1;
    int idx_q = -1;
    int idx_cur = -1;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        inorder(root, p, q, 0);
        
        // find the smallest level between idxp and idxq
        TreeNode* ans_node = nullptr;
        int smallest_level = INT_MAX;
        if (idx_p > idx_q) swap(idx_p, idx_q);
        for (int i = idx_p; i <= idx_q; i++) {
            if (levels[i].second < smallest_level) {
                smallest_level = levels[i].second;
                ans_node = levels[i].first;
            }
        }
        return ans_node;
    }
    /* 
        vector<pair<TreeNode*, int>> levels;
        int idx_p = -1;
        int idx_q = -1;
     */
    void inorder(TreeNode* root, TreeNode* p, TreeNode* q, int level) {
        if (!root)
            return;
        // early stop
        if (idx_p != -1 && idx_q != -1)
            return;
        
        inorder(root->left, p, q, level + 1);
        
        idx_cur++;
        if (root->val == p->val) 
            idx_p = idx_cur;
        if (root->val == q->val) 
            idx_q = idx_cur;
        levels.push_back({root, level});

        inorder(root->right, p, q, level + 1);
    }
};

/* 
       1
    2.    3
  4   

    found_p
    found_q
    
    record the corresponding index of node p and q

    order: 4 -> 2 -> 1 -> 3
    level: 3.   2    1    2  (array)
 */