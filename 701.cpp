/*
    iterative with/without ptr-to-ptr
    T:O(n)/S:O(1)
    -----
    recursive
    T:O(n)/S:O(n)
*/
/***** iterative without ptr-to-ptr *****/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        TreeNode *cur=root, *prev=0;
        while(cur) {
            prev=cur;
            if (cur->val>val) cur=cur->left;
            else cur=cur->right;
        }
        TreeNode *node=new TreeNode(val);
        if (prev&&val>prev->val) prev->right=node;
        else if (prev) prev->left=node;
        return prev?root:node;
    }
};

/***** iterative with ptr-to-ptr *****/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        TreeNode **cur=&root;
        while(*cur){
            cur=((*cur)->val>val)?&(*cur)->left:&(*cur)->right;
        }
        *cur=new TreeNode(val);
        return root;
    }
};

/***** recursive *****/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if (!root) return new TreeNode(val);
        else if (root->val>val)
            root->left=insertIntoBST(root->left,val);
        else
            root->right=insertIntoBST(root->right,val);
        return root;
    }
};
