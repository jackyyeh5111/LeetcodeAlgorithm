/***** Fourth Visit *****/
/*
    B0
    B1
    B2=B1N NB1
    B3=B2N NB2 B1NB1
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n)
    {
        vector<vector<TreeNode*>> dp(n+1,vector<TreeNode*>{});
        dp[0].push_back(0);
        dp[1].push_back(new TreeNode());
        for (int i=2; i<=n; ++i) {
            for (int j=0; j<i; ++j) {
                auto lefts=dp[j];
                auto rights=dp[i-j-1];
                for (auto l:lefts) {
                    for (auto r:rights) {
                        TreeNode *node=new TreeNode();
                        node->left=l;
                        node->right=r;
                        dp[i].push_back(node);
                    }
                }
            }
        }
        for (auto &tree:dp[n]) {
            int val=1;
            tree=deepCopy(tree,val);
        }
        return dp[n];
    }

    TreeNode* deepCopy(TreeNode *root, int &val)
    {
        if (!root) return 0;
        TreeNode *node=new TreeNode();
        node->left=deepCopy(root->left,val);
        node->val=val++;
        node->right=deepCopy(root->right,val);
        return node;
    }
};

/***** Third Visit *****/
/*
    Catalan Number
    T(n):1/(n+1)*C^2n_n
    B0=0
    B1=1
    B2=B1B0, B0B1
    B3=B0B2, B1B1, B2B0
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n)
    {
        if (n==0) return {};
        vector<vector<TreeNode*>> dp(n+1,vector<TreeNode*>{});
        dp[0]={0};
        dp[1]={new TreeNode()};
        for (int i=2; i<=n; ++i) {
            for (int j=0; j<i; ++j) {
                auto lefts=dp[j];
                auto rights=dp[i-j-1];
                for (auto l:lefts) {
                    for (auto r:rights) {
                        TreeNode *node=new TreeNode();
                        node->left=l; node->right=r;
                        dp[i].push_back(node);
                    }
                }
            }
        }
        for (auto &tree:dp[n]) {
            int val=1;
            tree=clone(tree,val);
        }
        return dp[n];
    }

    TreeNode *clone(TreeNode *root, int &val)
    {
        if (!root) return 0;
        TreeNode *left=clone(root->left,val);
        TreeNode *node=new TreeNode(val++);
        TreeNode *right=clone(root->right,val);
        node->left=left; node->right=right;
        return node;
    }
};

/***** Second Visit *****/
/*
    catalan number: (1/n+1 C^2n_n)
    B0=1
    B1=1
    B2=B0B1,B1B0
    B3=B0B2,B1B1,B2B0
    dp approach

    Actually we can ensure that left part starts from 0-j, and the root value is j+1. Thus all the right subtrees need to be added by offset j+1.
    Accordingly, we just nened to clone right subtree with offset, instread of whole tree.
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n)
    {
        if (n==0) return {};
        vector<vector<TreeNode*>> dp(n+1,vector<TreeNode*>{});
        dp[0]=vector<TreeNode*>{0};
        dp[1]=vector<TreeNode*>{new TreeNode(1)};
        for (int i=2; i<=n; ++i) {
            for (int j=0; j<i; ++j) {
                auto left=dp[j];
                auto right=dp[i-1-j];
                for(auto l:left){
                    for (auto r:right){
                        TreeNode *node=new TreeNode();
                        node->left=l; node->right=r;
                        dp[i].push_back(node);
                    }
                }
            }
        }
        for(auto &tree:dp[n]) {int start=1; tree=duplicateBST(tree,start);}
        return dp[n];
    }

    TreeNode* duplicateBST(TreeNode *root, int &val)
    {
        if(!root) return 0;
        TreeNode *node=new TreeNode();
        node->left=duplicateBST(root->left, val);
        node->val=val++;
        node->right=duplicateBST(root->right, val);
        return node;
    }
};

/***** First Visit *****/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n)
    {
        /*
            Catalan Number again
            combinations: 1/(n+1) C^2n_n

            recursive may cause TLE, use DP.
            B2=B0B1+B1B0
            B3=B0B2+B1B1+B2B0
            B4=B0B3+B1B2+B2B1+B3B0
        */
        if (n==0) return vector<TreeNode*>{};
        vector<vector<TreeNode*>> dp(n+1,vector<TreeNode*>{});
        dp[0].push_back(0);
        dp[1].push_back(new TreeNode(1));
        for (int i=2; i<=n; ++i) {
            vector<TreeNode*> tmp;
            for (int j=0; j<i; ++j) {
                vector<TreeNode*> lefts=dp[j];
                vector<TreeNode*> rights=dp[i-1-j];
                for (auto left:lefts) {
                    for (auto right: rights) {
                        TreeNode* root=new TreeNode(i);
                        root->left=left;
                        root->right=right;
                        tmp.push_back(root);
                    }
                }
            }
            dp[i]=tmp;
        }
        for (auto &tree: dp[n]) {
            int start=1;
            tree = fillBST(tree, start);
        }
        return dp[n];
    }

    TreeNode* fillBST(TreeNode *root, int &val)
    {
        if (!root) return 0;
        TreeNode *new_root=new TreeNode(0);
        if (root->left) new_root->left=fillBST(root->left, val);
        new_root->val=val++;
        if (root->right) new_root->right=fillBST(root->right, val);
        return new_root;
    }
};
