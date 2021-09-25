/***** Fifth Visit *****/
/*
    BST <-> inorder: increasing
    inorder traversal recursive
    T:O(n)/S:O(n)
    -----
    morris traversal
*/
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        TreeNode *prev=0, *cur=root;
        bool valid=true;
        while (cur) {
            if (!cur->left) {
                //visit
                if (!prev) prev=cur;
                else if (cur->val<=prev->val) valid=false;
                prev=cur;
                cur=cur->right;
            }
            else {
                TreeNode *pred=cur->left;
                while (pred->right&&pred->right!=cur) pred=pred->right;
                if (pred->right==cur) {
                    // visit
                    pred->right=0;
                    if (!prev) prev=cur;
                    else if (cur->val<=prev->val) valid=false;
                    prev=cur;
                    cur=cur->right;
                }
                else {
                    pred->right=cur;
                    cur=cur->left;
                }
            }
        }
        return valid;
    }
};

/***** Fourth Visit *****/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return preorder(root,(long)INT_MIN-1,(long)INT_MAX+1);
    }

    bool preorder(TreeNode *root, long lower,long upper)
    {
        if (!root) return true;
        if (root->val<=lower||root->val>=upper) return false;
        return preorder(root->left,lower,root->val)&&
               preorder(root->right,root->val,upper);
    }
};

/***** Third Visit *****/
/*
    Vavlidate BST or not.
    If we apply top down, i.e. preorder, we may miss the one with larger pred .
    Apply bottom up, i.e. postorder. Carry current min/max while backtracking.
    T:O(n)/S:O(n), use morris traversal for further reduce space complexity.
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool ans=true;
        postOrder(root,ans);
        return ans;
    }

    // min, max
    pair<long,long> postOrder(TreeNode *root, bool &ans)
    {
        if (!root) return {(long)INT_MAX+1,(long)INT_MIN-1};
        auto left=postOrder(root->left, ans);
        auto right=postOrder(root->right, ans);
        if (left.second>=root->val||right.first<=root->val) ans=false;
        return {min(left.first,(long)root->val),max(right.second,(long)root->val)};

    }
};

/***** Second Visit *****/
/*
    inorder checking
    T:O(n)/S:O(n)
    -----
    Notice that not only check current node's left/right but also need to check its predecessor and successor.
*/
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        double start=(double)INT_MIN-1.0;
        return help(root,start);
    }

    bool help(TreeNode *node, double &val)
    {
        if (!node) return true;
        if(!help(node->left,val)) return false;
        if(val>=node->val) return false;
        val=node->val;
        if(!help(node->right,val)) return false;
        return true;
    }
};

/***** First Visit *****/
class Solution {
public:

    bool isValidBST(TreeNode* root)
    {
        if (!root) return true;
        bool left = isValidBST(root->left);
        bool right = isValidBST(root->right);

        bool checkLeft=true, checkRight=true;
        if (root->left&&root->left->val>=root->val) checkLeft=false;
        if (root->right&&root->right->val<=root->val) checkRight=false;

        bool checkpred=true, checksucc=true;
        TreeNode *pred=0, *succ=0;
        pred=root->left;
        while(pred&&pred->right) pred=pred->right;
        succ=root->right;
        while(succ&&succ->left) succ=succ->left;
        if(pred&&root->val<=pred->val) checkpred=false;
        if(succ&&root->val>=succ->val) checksucc=false;
        return checkLeft&&checkRight&&left&&right&&checkpred&&checksucc;
    }
};
/*
[2,1,3]
[5,1,4,null,null,3,6]
[1,1]
[10,5,15,null,null,6,20]
*/
