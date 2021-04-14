/***** Fourth Visit *****/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        else return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

/***** Third Visit *****/
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (!root) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return max(left,right)+1;
    }
};

/***** Second Visit *****/
/*
    preorder NLR traversal. starts from 0.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (!root) return 0;
        else return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

/***** First Visit *****/
/***************** recursive ******************/
// T:O(n), S:O(logn)
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (!root) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
