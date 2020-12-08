/*
    keep the node's subtree total sum while bottom-up recursive
    bottom-up -> LRN, i.e. post order traversal
    return the sum of every tree node's tilt.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int findTilt(TreeNode* root)
    {
        return help(root).second;
    }

    // <total sum, total tilt>
    pair<int,int> help(TreeNode *root)
    {
        if (!root) return {0,0};
        auto left=help(root->left);
        auto right=help(root->right);
        return { left.first+right.first+root->val,
                 left.second+right.second+abs(left.first-right.first) };
    }
};
