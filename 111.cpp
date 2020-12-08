/***** Third Visit *****/
/*
    postorder Traversal
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if (!root) return 0;
        else if (!root->left&&!root->right) return 1;
        else if (root->left&&root->right) return min(minDepth(root->left),minDepth(root->right))+1;
        else if (root->left) return minDepth(root->left)+1;
        else return minDepth(root->right)+1;
    }
};

/***** Second Visit *****/
 /*
    NLR traversal.
    Note that min depth means the min distance between root to LEAF,
    thus we should take care about nodes with single child. Its not a leaf!
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if (!root) return 0;
        else if (!root->left&&!root->right) return 1;
        else if (!root->left) return minDepth(root->right)+1;
        else if (!root->right) return minDepth(root->left)+1;
        else return min(minDepth(root->left),minDepth(root->right))+1;
    }
};

/***** First Visit *****/
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        /*
            find the min path from root to leaf
            just use DFS traverse and check minDepth instead of maxDepth
            Note: A leaf is a node with NO children.
            T:O(n), S:O(logn)
            ------------------------
            We can use queue for an iterative approach and early stop while we
            first meet the node with no children.
        */
        if(!root) return 0;
        if(!root->left&&!root->right) return 1;
        int left=INT_MAX,right=INT_MAX;
        if(root->left) left=minDepth(root->left);
        if(root->right) right=minDepth(root->right);
        return min(left,right)+1;
    }
};
