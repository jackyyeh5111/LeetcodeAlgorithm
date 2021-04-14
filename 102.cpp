/***** Third Visit *****/
/*
    queue/preorder
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int k=q.size();
            ans.push_back({});
            for (int i=0; i<k; ++i) {
                auto node=q.front(); q.pop();
                ans.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        preorder(root,ans,0);
        return ans;
    }

    void preorder(TreeNode *root, vector<vector<int>> &ans, int depth)
    {
        if (!root) return;
        if (ans.size()==depth) ans.push_back({});
        ans[depth].push_back(root->val);
        preorder(root->left,ans,depth+1);
        preorder(root->right,ans,depth+1);
    }
};

/***** Second Visit *****/
/*
    level order traversal -> use queue+iteration
    T:O(n)/S:O(n)
    -----
    preorder traversal
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while (!q.empty()) {
            int k=q.size();
            vector<int> v;
            for (int i=0; i<k; ++i) {
                TreeNode *node=q.front(); q.pop();
                v.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        help(root, 0, ans);
        return ans;
    }

    void help(TreeNode *root, int depth, vector<vector<int>> &ans)
    {
        if (!root) return;
        if (depth>=ans.size()) ans.push_back(vector<int>{});
        ans[depth].push_back(root->val);
        help(root->left,depth+1,ans);
        help(root->right,depth+1,ans);
    }
};

/***** First Visit *****/
 /*
    While having level order, we just need to ensure one thing:
        The root node is traced before all its child node.
    Thus, we can adopt queue for iteration and preorder(NLR) for recursive.
 */

/************* Queue ************/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        /*
            tree level order: QUEUE!
            T:O(n), S:O(n)
        */
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while(!q.empty()) {
            int size=q.size();
            vector<int> level;
            for(int i=0; i<size; ++i){
                TreeNode *node=q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

/************* preorder traversal ************/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        help(root, 0);
        return ans;
    }

    void help(TreeNode *root, int depth)
    {
        if(!root) return;
        if(depth==ans.size())
            ans.push_back(vector<int>{});
        ans[depth].push_back(root->val);
        help(root->left, depth+1);
        help(root->right, depth+1);
    }
};
