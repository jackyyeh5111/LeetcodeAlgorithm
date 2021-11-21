/***** Third Visit *****/
/*
    BST -> inorder traversal can return increasing order.
    constraint: SC: O(1) -> morris traversal.
    T:O(n)
    0 1 8 3 4 5 2
        ^
*/
class Solution {
public:
    void recoverTree(TreeNode* root)
    {
        TreeNode *cur=root, *prev=0;
        vector<TreeNode*> v;
        while (cur) {
            if (!cur->left) {
                // visit cur
                if (v.size()==0&&prev&&cur->val<prev->val) v.push_back(prev);
                else if (v.size()!=0&&cur->val>=v[0]->val) v.push_back(prev);
                prev=cur;
                cur=cur->right;
            }
            else {
                TreeNode *pred=cur->left;
                while (pred->right&&pred->right!=cur) pred=pred->right;
                if (pred->right==cur) {
                    // visit cur
                    if (v.size()==0&&prev&&cur->val<prev->val) v.push_back(prev);
                    else if (v.size()!=0&&cur->val>=v[0]->val) v.push_back(prev);
                    pred->right=0;
                    prev=cur;
                    cur=cur->right;
                }
                else {
                    pred->right=cur;
                    cur=cur->left;
                }
            }
        }
        if (v.size()<2) v.push_back(prev);
        swap(v[0]->val,v[1]->val);
    }
};

/***** Second Visit *****/
/*
    Constant space complexity while tree traversal: morris traversal.
    for each node, find its inorder predecessor and link them for S:O(1) traversal.
    iterative solution.
    Thought: utilize all leaf's null ptr and save the O(n) stack utilization.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    void recoverTree(TreeNode* root)
    {
        TreeNode *cur=root, *prev=0, *nodea=0, *nodeb=0;
        while (cur) {
            if (!cur->left) {
                // visit
                if (!prev) prev=cur;
                else {
                    if (prev->val>=cur->val&&!nodea) nodea=prev;
                    if (nodea&&cur->val<nodea->val) nodeb=cur;
                    prev=cur;
                }
                // cout<<cur->val<<endl;
                cur=cur->right;
            }
            else {
                TreeNode *pred=cur->left;
                while(pred&&pred->right&&pred->right!=cur) pred=pred->right;
                if (pred->right==cur) {
                    pred->right=0;
                    // visit
                    if (prev->val>=cur->val&&!nodea) nodea=prev;
                    if (nodea&&cur->val<nodea->val) nodeb=cur;
                    prev=cur;
                    // cout<<cur->val<<endl;
                    cur=cur->right;
                }
                else {
                    pred->right=cur;
                    cur=cur->left;
                }
            }
        }
        swap(nodea->val,nodeb->val);
    }
};

/***** First Visit *****/
 /*
 inorder traversal
     record each node's ptr and the sequence, and we'll find our target
     like: 12543 <- swap(5,3)
     T:O(n), S:O(n+n)
 ----------------------
 we can find our target, i.e. the wrong one, by inorder and inverse inorder.
 inorder: small->large
 inverse inorder: large->small

 left: 321 swap(3,1)
 right: 123

 left: 1324 swap(3,2)
 right: 4231

 12745638
 T:O(n), S:O(logn)
 ----------------------
 use threaded binary tree to reduce space complexity
 T:O(n), S:O(1)
 */

/************* O(1) morris inorder traversal  *************/
// refers to https://youtu.be/wGXB9OWhPTg
// T:O(n)/S:O(1)
 class Solution {
 public:
     void recoverTree(TreeNode* root)
     {
         TreeNode *cur=root, *pred=0, *prev=0;
         vector<TreeNode*> targets;
         while (cur) {
             if (!cur->left) {
                 //visit
                 // if(prev)cout<<prev->val<<endl;
                 if(prev&&prev->val>cur->val&&targets.size()==0) {
                     targets.push_back(prev);
                 }
                 else if (targets.size()==1&&cur->val>targets[0]->val) {
                     targets.push_back(prev);
                 }
                 prev=cur;
                 cur=cur->right;
             }
             else {
                 pred=cur->left;
                 while(pred->right&&pred->right!=cur) pred=pred->right;
                 if(!pred->right){
                     pred->right=cur;
                     cur=cur->left;
                 }
                 else { // pred->right==cur
                     //visit
                     // if(prev)cout<<prev->val<<endl;
                     if(prev&&prev->val>cur->val&&targets.size()==0) {
                     targets.push_back(prev);
                     }
                     else if (targets.size()==1&&cur->val>targets[0]->val) {
                         targets.push_back(prev);
                     }
                     prev=cur;
                     pred->right=0; // recover the tree.
                     cur=cur->right;
                 }
             }
         }
         if (targets.size()==2)
             swap(targets[0]->val,targets[1]->val);
         else
             swap(targets[0]->val,prev->val);
     }
 };

/************* O(n) inorder traversal  *************/
// T:O(n)/S:O(n)
class Solution {
public:
    TreeNode *leftTarget=0, *rightTarget=0;
    bool leftFound=false, rightFound=false;
    void recoverTree(TreeNode* root)
    {
        inorder(root); inverseInorder(root);
        swap(leftTarget->val, rightTarget->val);
    }

    void inorder(TreeNode* root)
    {
        if (!root) return;
        inorder(root->left);
        if (!leftFound&&(!leftTarget||leftTarget->val<=root->val)) leftTarget=root;
        else { leftFound=true; return;}
        inorder(root->right);
    }

    void inverseInorder(TreeNode* root)
    {
        if (!root) return;
        inverseInorder(root->right);
        if (!rightFound&&(!rightTarget||rightTarget->val>=root->val)) rightTarget=root;
        else { rightFound=true; return;}
        inverseInorder(root->left);
    }
};
