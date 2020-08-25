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
/*
    traverse the tree with preorder, which guarentee that vertical order in same X.
    T:O(n)/S:O(n)
    !!!!!!!! Actually is O(n+nlogn) !!!!!!!!
    Time complexity: dfs traversal O(n) + AVL tree O(nlogn)
*/
class Solution {
public:
    map<int,map<int,vector<int>>> m;
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        help(root, 0, 0);
        vector<vector<int>> ans;
        for (auto it=m.begin(); it!=m.end(); ++it){
            auto y=it->second;
            vector<int> col;
            for (auto it2=y.begin(); it2!=y.end(); ++it2) {
                vector<int> v=it2->second;
                sort(v.begin(), v.end());
                col.insert(col.end(),v.begin(),v.end());
            }
            ans.push_back(col);
        }
        return ans;
    }

    void help(TreeNode* root, int x, int y)
    {
        if (!root) return;
        if (m.find(x)==m.end()||m[x].find(y)==m[x].end())
            m[x][y]=vector<int>{};
        m[x][y].push_back(root->val);
        help(root->left,x-1,y+1);
        help(root->right,x+1,y+1);
    }
};
