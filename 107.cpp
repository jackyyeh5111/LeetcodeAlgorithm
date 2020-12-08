/*
    iterative (slow)
    queue approach -> T:O(k^2), k: depth/ S:O(n)
    -----
    recursive (fast)
    get depth k T:O(n)/S:O(n)
    preorder traverse T:O(n)/S:O(n)
    T:O(n)/S:O(n)
*/
/***** Third Visit *****/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int k=q.size();
            vector<int> v;
            for(int i=0; i<k; ++i) {
                TreeNode *node=q.front(); q.pop();
                v.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.insert(ans.begin(),v);
        }
        return ans;
    }
};

/***** Second Visit *****/
// NLR T:O(n), 4ms
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        if(!root) return ans;
        int depth=getDepth(root);
        ans = vector<vector<int>>(depth,vector<int>{});
        help(root,depth,0);
        return ans;
    }

    void help(TreeNode* root, int depth, int level)
    {
        if(!root) return;
        ans[depth-level-1].push_back(root->val);
        help(root->left,depth,level+1);
        help(root->right,depth,level+1);
    }

    int getDepth(TreeNode *root)
    {
        if(!root) return 0;
        return max(getDepth(root->left),getDepth(root->right))+1;
    }
};

// levle order w. Q T:O(n), 64ms
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        queue<TreeNode*> q;
        if (root) q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            int size=q.size();
            vector<int> level;
            for (int i=0; i<size; ++i) {
                TreeNode *node=q.front(); q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.insert(ans.begin(),level);
        }
        return ans;
    }
};

/***** First Visit *****/
/******************** NLR traversal 8ms ***********************/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        int depth=getDepth(root);
        ans=vector<vector<int>>(depth,vector<int>{});
        levelTraverse(root, depth,0);
        return ans;
    }

    void levelTraverse(TreeNode *root, int depth, int level)
    {
        if(!root) return;
        ans[depth-level-1].push_back(root->val);
        levelTraverse(root->left,depth,level+1);
        levelTraverse(root->right,depth,level+1);
    }

    int getDepth(TreeNode *root)
    {
        if(!root) return 0;
        return max(getDepth(root->left),getDepth(root->right))+1;
    }
};

/*************** level order traversal(with queue) 54ms ******************/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while(!q.empty()) {
            int size=q.size();
            vector<int> level;
            for (int i=0; i<size; ++i) {
                TreeNode *node = q.front(); q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node->val);
            }
            ans.insert(ans.begin(),level);
        }
        return ans;
    }
};
