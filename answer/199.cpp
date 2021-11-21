/***** Fourth Visit *****/
/*
    preorder traversal: make sure that right node will be visited in the last order.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        int depth=0;
        preorder(root,depth,ans);
        return ans;
    }

    void preorder(TreeNode *root, int depth, vector<int> &ans)
    {
        if (!root) return;
        if (ans.size()==depth) ans.push_back(0);
        ans[depth]=root->val;
        preorder(root->left,depth+1,ans);
        preorder(root->right,depth+1,ans);
    }
};

/***** Third Visit *****/
/*
    use inorder or preorder traversal, which traverse right node in the last order.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        help(root,0,ans);
        return ans;
    }

    void help(TreeNode *root, int depth, vector<int> &ans)
    {
        if (!root) return;
        if (ans.size()==depth) ans.push_back(root->val);
        else ans[depth]=root->val;
        help(root->left,depth+1,ans);
        help(root->right,depth+1,ans);
    }
};

/***** Second Visit *****/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        /*
            preorder traversal, keep update latest entry of same level.
            T:O(n), S:O(n)
        */
        vector<int> ans;
        help(root, 0, ans);
        return ans;
    }

    void help(TreeNode *root, int level, vector<int> &ans)
    {
        if (!root) return;
        if (ans.size()<=level)
            ans.push_back(0);
        ans[level]=root->val;
        help(root->left, level+1, ans);
        help(root->right, level+1, ans);
    }
};

/***** First Visit *****/
/************************* NRL traversal *************************/
class Solution {
public:
    //T:O(n), S:O(n)
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        help(root,0);
        return ans;
    }

    void help(TreeNode* root, int level)
    {
        if (!root) return;
        if (ans.size()<=level) ans.push_back(root->val);
        help(root->right,level+1);
        help(root->left,level+1);
    }
};

/************************* levelorder traversal *************************/
class Solution {
public:
    //T:O(n), S:O(n)
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root) q.push(root);
        while(!q.empty()) {
            int size=q.size();
            for (int i=0;i<size;++i){
                TreeNode* node=q.front(); q.pop();
                if(i==size-1) ans.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return ans;
     }
};
