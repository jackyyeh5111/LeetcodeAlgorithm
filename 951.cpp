/***** Second Visit *****/
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2)
    {
        if (!root1&&!root2) return true;
        else if (!root1||!root2) return false;
        else if (root1->val!=root2->val) return false;
        else {
            bool flip=flipEquiv(root1->left, root2->right) &&
                      flipEquiv(root1->right,root2->left);
            bool notflip=flipEquiv(root1->right, root2->right) &&
                         flipEquiv(root1->left,root2->left);
            return flip||notflip;
        }

    }
};

/***** First Visit *****/
/*
    top-down NLR preorder checking
    T:O(n) 2 pass / S:O(n)
*/
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2)
    {
        if (!root1&&!root2) return true;
        else if (!root1||!root2) return false;
        else if (root1->val!=root2->val) return false;
        return (flipEquiv(root1->left,root2->left)&&flipEquiv(root1->right,root2->right))||
               (flipEquiv(root1->right,root2->left)&&flipEquiv(root1->left,root2->right));

    }
};
