// preorder traversal
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<double,double>> table;
        dfs(root,table,0);
        vector<double> ans;
        for (auto p:table) {
            ans.push_back(p.first/(double)p.second);
        }
        return ans;
    }

    void dfs(TreeNode *root, vector<pair<double,double>> &table, int depth)
    {
        if (!root) return;
        if (table.size()==depth) table.push_back({0,0});
        table[depth].first+=root->val;
        table[depth].second++;
        dfs(root->left,table,depth+1);
        dfs(root->right,table,depth+1);
    }
};

// level order traversal
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        queue<TreeNode*> q;
        vector<double> ans;
        if (root) q.push(root);
        while (!q.empty()) {
            int k=q.size();
            double t=0;
            for (int i=0; i<k; ++i) {
                auto node=q.front(); q.pop();
                t+=node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(t/(double)k);
        }
        return ans;
    }
};
