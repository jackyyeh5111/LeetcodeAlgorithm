/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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
