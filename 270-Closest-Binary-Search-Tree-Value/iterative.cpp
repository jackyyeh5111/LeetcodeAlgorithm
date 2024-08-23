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
    int closestValue(TreeNode* root, double target) {
        
        // iterative approach
        stack<TreeNode* > stk;
        int prev = INT_MAX;
        while(root || !stk.empty()) {
            while(root) {
                stk.push(root);
                root = root->left;
            }
            TreeNode *node = stk.top();
            stk.pop();
            if (target < node->val) {
                if (prev == INT_MAX) return node->val;
                return (target - prev <= node->val - target) ? prev : node->val;
            }
            
            prev = node->val; // update prev
            root = node->right;
        }
        
        return prev; // return the max value in tree
    }
};

/* 
    Approach:
        1. recursive(inorder) + linear search => time: O(n), space: O(Height)
        2. iterative => time: O(k), space: O(Height)
        3. binary search => time: O(Height)
 */