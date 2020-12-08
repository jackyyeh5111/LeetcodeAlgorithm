/*
    bfs -> level order traversal
    level by level checking with odd/even/odd ... etc.
    T:O(n)/S:O(n)
    -----
    dsf -> preorder traversal
    maintain a depth representing level and a vector for the latest num of each level.
    odd: strict increasing
    even: strict decreasing
    T:O(n)/S:O(n)
*/
class Solution {
public:
    bool isEvenOddTree(TreeNode* root)
    {
        vector<int> record;
        return feasible(root, 0, record);
    }

    bool feasible(TreeNode *root, int depth, vector<int> &record)
    {
        if (!root) return true;
        else if (root->val%2==depth%2) return false;
        if (record.size()==depth)
            record.push_back(root->val);
        else if (depth%2==0&&root->val<=record[depth]) return false;
        else if (depth%2!=0&&root->val>=record[depth]) return false;
        record[depth]=root->val;
        return feasible(root->left, depth+1, record) &&
               feasible(root->right, depth+1, record);
    }
};
