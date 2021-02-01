/***** Third Visit *****/
/*
    postOrder traversal
    T:O(n)/S:O(n)
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root) return 0;
        if (root==p||root==q) return root;
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        if (left&&right) return root;
        else if(!left&&!right) return 0;
        else return left?left:right;

    }
};

/***** Second Visit *****/
// w.o. help function
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (p==q) return p;
        else if (!root) return 0;
        else if (root==p||root==q) return root;
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        if (left&&right) return root;
        else if (left) return left;
        else if (right) return right;
        else return 0;
    }
};

// w. help  function
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (p==q) return p;
        TreeNode *ans=0;
        help(root,p,q,&ans);
        return ans;
    }

    bool help(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode **ans)
    {
        if (!root) return false;
        bool left=help(root->left,p,q,ans);
        bool right=help(root->right,p,q,ans);
        bool cur=(root==p)||(root==q);
        if ((left&&right)||(left&&cur)||(right&&cur))
            *ans=root;
        return left||right||cur;
    }
};

/***** First Visit *****/
/*
    According to problem 235, we know that we can use 2 path vector to find the lowest common
    ancestor.
    T:O(n)/S:O(n+2n)
    ------------
    NLR traversal to find the very first one node which has 2 of 3 :
        1. find pq in left.
        2. find pq in right.
        3. find pq in current node.
    Then this very first node is the least commonancestor.
    T:O(n)/S:O(n)
*/

/******* No extra container but help function *******/
class Solution {
public:
    TreeNode *ans=0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        help(root,p,q);
        return ans;
    }

    bool help(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root) return false;
        bool left=help(root->left,p,q);
        bool right=help(root->right,p,q);
        bool cur=false;
        if (root==p||root==q) cur=true;
        if ((cur+left+right)>=2 && !ans) ans=root;
        return left||right||cur;
    }
};

/******* No extra container and help function *******/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root||root==p||root==q) return root;
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        if (!left&&!right) return 0;
        else if (left&&right) return root;
        else return left ? left : right;
    }
};

/******* 2 extra path container *******/
class Solution {
public:
    vector<TreeNode*> p_path, q_path;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        vector<TreeNode*> path;
        help(root,p,q,path);
        TreeNode *ans=root;
        int i=0,j=0;
        while(i<p_path.size()&&j<q_path.size()) {
            if (p_path[i]!=q_path[j]) break;
            ans=p_path[i];
            i++; j++;
        }
        return ans;
    }

    void help(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*> &path)
    {
        if (!root) return;
        path.push_back(root);
        if (root==p) p_path=path;
        if (root==q) q_path=path;
        if(p_path.size()!=0&&q_path.size()!=0) return; //early stop
        help(root->left,p,q,path);
        help(root->right,p,q,path);
        path.pop_back();
    }
};
