/***** Third Visit *****/
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s&&!t) return true;
        else if (!s||!t) return false;

        return isSubtree(s->left,t)||isSubtree(s->right,t)||help(s,t);

    }

    bool help(TreeNode *s, TreeNode *t)
    {
        if (!s&&!t) return true;
        else if (!s||!t) return false;
        else if (s->val!=t->val) return false;
        else return help(s->left,t->left)&&help(s->right,t->right);
    }
};

/***** Second Visit *****/
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!t) return 1;
        else if (!s) return 0;
        if (s->val==t->val&&check(s,t)) return true;
        else return isSubtree(s->left,t)||isSubtree(s->right,t);
    }

    bool check(TreeNode *s, TreeNode *t)
    {
        if (!s&&!t) return 1;
        else if (!s||!t||s->val!=t->val) return 0;
        return check(s->left,t->left)&&check(s->right,t->right);
    }
};

/***** First Visit *****/
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {

        if (!s&&!t) return true;
        else if (!s||!t) return false;
        bool same=false;
        if (s->val==t->val) same|=isSame(s,t);
        same|=isSubtree(s->left,t);
        same|=isSubtree(s->right,t);
        return same;
    }

    bool isSame(TreeNode *s, TreeNode *t)
    {
        if (!s&&!t) return true;
        else if (!s||!t) return false;
        else if (s->val!=t->val) return false;
        return isSame(s->left,t->left)&&isSame(s->right,t->right);
    }
};
