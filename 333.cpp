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
    int ans = 0;
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        postorder(root);
        return ans;
    }
    vector<int> postorder(TreeNode* root) {
        if (!root) return {INT_MAX, INT_MIN, 0};
        auto left = postorder(root->left);
        auto right = postorder(root->right);
        
        // not valid subtree
        if (left[2] == -1 || right[2] == -1) return {-1, -1, -1};

        if (root->val > left[1] && root->val < right[0])  {
            int num_nodes = left[2] + right[2] + 1;
            ans = max(ans, num_nodes);
            int min_val = min(left[0], root->val);
            int max_val = max(right[1], root->val);
            return {min_val, max_val, num_nodes};
        }
        
        return {-1, -1, -1};
    }
};

/* 
    Use "postorder traversal"
    Pass the number of nodes in the current subtree up to the parent as well to get the size of the current tree in constant time.
    
    vector<int> postorder(TreeNode*)  // return {min, max, num_nodes}
    If (num_nodes == -1), it represents that subtree is not valid.

                       [3] [-1, -1, -1]
                  /           \
             [2] [(2, 2), 1]   [4] [(1, 4), 2]
                               /   
                            [1] [(1, 1), 1] // [(min, max), num_nodes]

 */