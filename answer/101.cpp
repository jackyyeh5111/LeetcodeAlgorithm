/***** Second Visit *****/
/*
    NLR preorder traversal with recursive comparison.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if (!root) return true;
        return help(root->left,root->right);
    }


    bool help(TreeNode *left, TreeNode *right)
    {
        if (!left&&!right) return true;
        else if (!left||!right||left->val!=right->val) return false;
        return help(left->left, right->right)&&help(left->right,right->left);
    }
};

/***** First Visit *****/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return help(root->left, root->right);
    }

    bool help(TreeNode *root1, TreeNode *root2)
    {
        if (!root1&&!root2) return true;
        else if (!root1||!root2) return false;
        else if (root1->val!=root2->val) return false;
        else return help(root1->left, root2->right)&&
                    help(root1->right, root2->left);
    }
};
