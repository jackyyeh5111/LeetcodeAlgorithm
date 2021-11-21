/***** Second Visit *****/
/*
    hybrid of preorder / postorder
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if (root) {
            ans.push_back(root->val);
            dfs(root->left,1,0,ans);
            dfs(root->right,0,1,ans);
        }
        return ans;
    }

    void dfs(TreeNode *root, bool lb, bool rb, vector<int> &ans)
    {
        if (!root) return;
        if (lb) ans.push_back(root->val);
        else if (!rb&&!root->left&&!root->right) ans.push_back(root->val);
        dfs(root->left,lb,rb&&!root->right,ans);
        dfs(root->right,lb&&!root->left,rb,ans);
        if (rb) ans.push_back(root->val);
    }
};

/***** First Visit *****/
// preorder + postorder hybrid
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<int> ans={root->val};
        dfs(root->left,1,0,ans);
        dfs(root->right,0,1,ans);
        return ans;
    }

    void dfs(TreeNode *root, bool lb, bool rb, vector<int> &ans)
    {
        if (!root) return;
        else if (lb) ans.push_back(root->val);
        else if (!rb&&!root->left&&!root->right) ans.push_back(root->val);
        dfs(root->left,lb,rb&&!root->right,ans);
        dfs(root->right,lb&&!root->left,rb,ans);
        if (rb) ans.push_back(root->val);
    }
};

// NLR + NRL
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root)
    {
        vector<int> left,right;
        if (!root) return {};
        left.push_back(root->val);
        dfsLeft(root->left,true,left);
        dfsRight(root->right,true,right);
        for(int i=right.size()-1; i>=0; --i) left.push_back(right[i]);
        return left;
    }

    // NLR
    void dfsLeft (TreeNode *root, bool found, vector<int> &ans)
    {
        if (!root) return;
        if (found) ans.push_back(root->val);
        else if (!root->left&&!root->right) ans.push_back(root->val);
        if (root->left){
            dfsLeft(root->left,found,ans);
            dfsLeft(root->right,false,ans);
        }
        else dfsLeft(root->right,found,ans);
    }

    // NRL
    void dfsRight (TreeNode *root, bool found, vector<int> &ans)
    {
        if (!root) return;
        if (found) ans.push_back(root->val);
        else if (!root->left&&!root->right) ans.push_back(root->val);
        if (root->right){
            dfsRight(root->right,found,ans);
            dfsRight(root->left,false,ans);
        }
        else dfsRight(root->left,found,ans);
    }
};
