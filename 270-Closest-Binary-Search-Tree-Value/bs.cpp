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
    int closest;
    int closestValue(TreeNode* root, double target) {
        closest = root->val;
        binarySearch(root, target);
        return closest;
    }
    void binarySearch(TreeNode* node, double target) {
        if (!node) return;
        if (abs(target - closest) > abs(target - node->val))
            closest = node->val;
        else if (abs(target - closest) == abs(target - node->val))
            closest = min(closest, node->val);

        if (node->val < target)
            binarySearch(node->right, target);
        else 
            binarySearch(node->left, target);
    }
};

/* 
    Approach:
        1. recursive(inorder) + linear search => time: O(n), space: O(Height)
        2. iterative => time: O(k), space: O(Height)
            works fine when indexing k of the closest element is much smaller than the tree height H.
        3. binary search => time: O(Height)
 */