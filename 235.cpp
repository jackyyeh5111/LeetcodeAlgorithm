/***** Second Visit *****/
/*
    ancestor finding
    a
     \
      b

       x
      / \
     a   b

    post order traversal and find the node with left&&right || left&&cur || rigjt&&cur
    T:O(n)/S:O(n)
    -----
    Utilize BST property!!!! p<=root<=q, return root, else traverse left or right.
    T:O(h)/S:O(h)
*/
// Could apply to non-BST
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

// Utilize BST property
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (p==q) return p;
        else if (p->val>q->val)  swap(p,q);
        while (!(root->val>=p->val&&root->val<=q->val)) {
            if (p->val>root->val) root=root->right;
            else root=root->left;
        }
        return root;
    }
};

/***** First Visit *****/
/*
    use preorder traversal to track p q path then find union.
    T:O(n) 2 pass, S:O(n)
    --------------
    Here our tree is binary tree, so common ancestor of p/q is right the node
    that p->val<=node->val<=q->val
    T:O(n)/S:O(1)
*/
/****** iterative ******/
class Solution {
public:
    vector<TreeNode*> p_path,q_path;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (q->val<p->val) swap(p,q);
        // cout<<p->val<<q->val<<endl;
        while(!(root->val>=p->val&&root->val<=q->val)) {
            // cout<<root->val<<endl;
            if (root->val>q->val) root=root->left;
            else root=root->right;
        }
        return root;
    }
};

/****** 2 pass solution ******/
class Solution {
public:
    vector<TreeNode*> p_path,q_path;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        vector<TreeNode*> path;
        help(root,p,q,path);
        TreeNode *ans=root;
        int i=0,j=0;
        while(i<p_path.size()&&j<q_path.size()) {
            // cout<<p_path[i]->val<<","<<q_path[j]->val<<endl;
            if(p_path[i]!=q_path[j]) break;
            ans=p_path[i];
            i++; j++;
        }
        return ans;
    }

    void help(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode*> &path)
    {
        if (!root) return;
        path.push_back(root);
        if (root==p) p_path=path;
        else if (root==q) q_path=path;
        help(root->left,p,q,path);
        help(root->right,p,q,path);
        path.pop_back();
    }
};
