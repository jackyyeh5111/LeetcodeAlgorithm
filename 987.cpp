/***** Second Visit *****/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        map<int,map<int,vector<int>>> m;
        help(root, m, 0, 0);
        vector<vector<int>> ans;
        for(auto xit=m.begin(); xit!=m.end(); ++xit) {
            ans.push_back(vector<int>{});
            auto ymap=xit->second;
            for (auto yit=ymap.begin(); yit!=ymap.end(); ++yit) {
                vector<int> tmp=yit->second;
                sort(tmp.begin(),tmp.end());
                for (int val:tmp)
                    ans.back().push_back(val);
            }
        }
        return ans;
    }

    void help(TreeNode *root, map<int,map<int,vector<int>>> &m, int x, int y)
     {
         if (!root) return;
         if (m.count(x)==0||m[x].count(y)==0)
             m[x][y]=vector<int>{};
         m[x][y].push_back(root->val);
         help(root->left, m, x-1, y+1);
         help(root->right, m, x+1, y+1);
     }
};

/***** First Visit *****/
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
