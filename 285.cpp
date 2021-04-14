/*
    recursive/iterative (morris traversal)
    T:O(n)/S:O(n) / T:O(n)/S:O(1)
    -----
    recursive logn
    Utilize the benefit of binary search tree.
    worst case T:O(H)/S:O(H)
*/

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        if (!root) return 0;
        if (root->val>p->val) {
            TreeNode *left=inorderSuccessor(root->left,p);
            return left?left:root;
        }
        else return inorderSuccessor(root->right,p);
    }
};

class Solution {
public:
    TreeNode *prev=0;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return 0;
        TreeNode *ret=inorderSuccessor(root->left,p);
        if (ret) return ret;
        if (prev==p) return root;
        prev=root;
        return inorderSuccessor(root->right,p);
    }
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        TreeNode *cur=root,*prev=0,*ans=0;
        while(cur) {
            if (!cur->left) {
                if (prev==p) ans=cur;
                prev=cur;
                cur=cur->right;
            }
            else {
                TreeNode *t=cur->left;
                while(t->right&&t->right!=cur) t=t->right;
                if (!t->right) {t->right=cur; cur=cur->left;}
                else {
                    t->right=0;
                    if (prev==p) ans=cur;
                    prev=cur;
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};
