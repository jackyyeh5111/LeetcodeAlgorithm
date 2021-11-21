/***** Fourth Visit *****/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p&&!q) return true;
        else if (!p||!q) return false;
        else return p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};

/***** Third Visit *****/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!p&&!q) return true;
        else if (!p||!q) return false;
        else return p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};

/***** Second Visit *****/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!p&&!q) return true;
        else if (!p||!q) return false;
        else if (p->val!=q->val) return false; // p, q are not null
        else return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};

/***** First Visit *****/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!p&&!q) return true;
        else if (!p||!q) return false;
        bool left=isSameTree(p->left, q->left);
        bool right=isSameTree(p->right, q->right);
        return left&&right&&p->val==q->val;
    }
};
