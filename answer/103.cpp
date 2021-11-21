/***** Third Visit *****/
/*
    Same problem as 102.
    Use iterative queue traversal and reverse odd level (start from 0).
    T:2 pass O(n)/S:O(n)
    -----
    preorder Traversal
    for level k, we have m nodes, than it cost O(m^2) inserting into the begin.
    T:O(n^2)/S:O(n) but actual cost is slightly higher than queue approach.
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        bool is_odd=false;
        while(!q.empty()) {
            int k=q.size();
            vector<int> v;
            for (int i=0; i<k; ++i) {
                TreeNode *node=q.front(); q.pop();
                v.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (is_odd) reverse(v.begin(),v.end());
            ans.push_back(v);
            is_odd = !is_odd;
        }
        return ans;
    }
};

/***** Second Visit *****/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        help(root, 0);
        return ans;
    }

    void help(TreeNode *root, int level)
    {
        if (!root) return;
        if (ans.size()<=level)
            ans.push_back(vector<int>{});
        if (level%2==1)
            ans[level].insert(ans[level].begin(), root->val);
        else
            ans[level].push_back(root->val);
        if (root->left) help(root->left, level+1);
        if (root->right) help(root->right, level+1);
    }
};
/***** First Visit *****/
/****************** level order traversal via queue *********************/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool fromLeft=false;
        if (root) q.push(root);
        while (!q.empty()) {
            int size=q.size();
            vector<int> level;
            for (int i=0; i<size; ++i) {
                TreeNode *node=q.front(); q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(fromLeft) reverse(level.begin(), level.end());
            ans.push_back(level);
            fromLeft=!fromLeft;
        }
        return ans;
    }
};

/****************** Preorder traversal *********************/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        help(root, 0);
        return ans;
    }

    void help(TreeNode* root, int depth)
    {
        if(!root) return;
        if (depth==ans.size())
            ans.push_back(vector<int>{});

        if (depth%2==0) ans[depth].push_back(root->val);
        else ans[depth].insert(ans[depth].begin(), root->val);
        help(root->left, depth+1);
        help(root->right, depth+1);
    }
};
