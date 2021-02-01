/***** Second Visit *****/
/*
    Thought 1:
    convert the tree to the graph
    apply bfs
    T:O(n)/S:O(n)
    -----
    postOrder to find distance to the target node.
    preOrder to find children beyond target node.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
    {
        vector<int> ans;
        findTarget(root,target,K,ans);
        dfs(target,K,ans);
        return ans;
    }

    int findTarget(TreeNode *root, TreeNode *target, int K,
                   vector<int> &ans)
    {
        if (root==target) return 1;
        else if (!root) return -1;
        int left=findTarget(root->left,target,K,ans);
        int right=findTarget(root->right,target,K,ans);
        if (left>=0&&K>=left) {
            if (K==left) ans.push_back(root->val);
            else dfs(root->right,K-left-1,ans);
        }
        if (right>=0&&K>=right) {
            if (K==right) ans.push_back(root->val);
            else dfs(root->left,K-right-1,ans);
        }
        return max(left,right)==-1?-1:max(left,right)+1;
    }

    void dfs(TreeNode *root, int K, vector<int> &ans)
    {
        if (!root) return;
        else if (K==0) {
            ans.push_back(root->val);
            return;
        }
        dfs(root->left,K-1,ans);
        dfs(root->right,K-1,ans);
    }
};

/***** First Visit *****/
/*
    DFS+postDFS
    dfs to find target node and further count the K distant nodes.
    postDFS to find parent/grandparent and siblings candidates.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
    {
         vector<int> ans;
         dfs(root,K,target,ans);
         return ans;
    }

    bool dfs(TreeNode *root, int &K, TreeNode*target, vector<int> &ans)
    {
        bool found=false;
        if (!root) return found;
        if (root==target) {
            help(root,K,ans);
            K--;
            return true;
        }
        if (dfs(root->left,K,target,ans)) {
            help(root->right,K-1,ans);
            found=true;
        }
        else if (dfs(root->right,K,target,ans)) {
             help(root->left,K-1,ans);
             found=true;
        }
        if (found&&K==0) ans.push_back(root->val);
        if (found) K--;
        return found;
    }

    void help(TreeNode *root, int K, vector<int> &ans)
    {
        if (!root||K<0) return;
        if (K==0) ans.push_back(root->val);
        help(root->left, K-1, ans);
        help(root->right, K-1, ans);
    }
};
