/*
    treat each path as a house robber I problem, but may fail on siblings
       > 3
        / \
       2   3
        \   \
       > 3   1
    3 2 3 3 1
         2
        / \
       1   3
        \
         4
    2 1 3 - 4
    -----
    As examples, we should sum up the values of same levels as one value.
    Treat each LEVEL as one house and we can have 1-d array tackled by house robber I.
    3 5 4
    3 12 4
    T:O(n)/S:O(n)
    STILL FAIL IN SIBLINGS
    -----
         2          6 max(1+3,1+0,4+3,4+0)
        / \
       1   3    (1,4)  (3,0)
        \
         4
    2 1 3 - 4
    post order traversal. backtracking with pair<choose, not choose>.
    notation: choose <-> l, not choose <-> r
    For each node, return
    <left.r+right.r+root->val,max(left.l,left.r)+max(right.l,right.r)>

    Follow up, what if we rob on spanning tree?
    > post dfs
*/
class Solution {
public:
    int rob(TreeNode* root)
    {
        auto ret=postOrder(root);
        return max(ret.first,ret.second);
    }

    pair<int,int> postOrder(TreeNode *root)
    {
        if (!root) return {0,0};
        auto left = postOrder(root->left);
        auto right = postOrder(root->right);
        return {root->val+left.second+right.second,
                max(left.first,left.second)+max(right.first,right.second)
               };
    }
};
