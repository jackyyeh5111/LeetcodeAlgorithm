/*
    maintain a table for sub nodes counting, node ptr.
    T:O(n)/S:O(n)
    -----
    Actually we just need to record left/child nodes, thus we dont need to use  additional hashmap table.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        unordered_map<int,pair<int,TreeNode*>> m;
        dfs(root,m);
        int left_num=0,right_num=0,parent_num=0;
        if (m[x].second->left) left_num=m[m[x].second->left->val].first;
        if (m[x].second->right) right_num=m[m[x].second->right->val].first;
        parent_num=n-left_num-right_num-1;
        if (left_num>n-left_num||right_num>n-right_num||parent_num>n-parent_num) return true;
        else return false;
    }

    // <key,<nodes,cur>>
    int dfs(TreeNode *root, unordered_map<int,pair<int,TreeNode*>> &m)
    {
        if (!root) return 0;
        int ret=dfs(root->left,m)+dfs(root->right,m)+1;
        m[root->val]={ret,root};
        return ret;
    }
};
