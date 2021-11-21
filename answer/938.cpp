/***** First Visit *****/
/*
    Binary Search Tree
    Use inorder traversal and conduct early Stop
    T(n)=2T(n/2)+O(1)
    T:O(n)/S:O(n)
    -----
    Utilize BST property
    T(n)=O(h)
*/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        if (!root) return 0;
        int ret=0;
        ret+=rangeSumBST(root->left,low,high);
        if (root->val<=high&&root->val>=low) ret+=root->val;
        else if (root->val>high) return ret;
        ret+=rangeSumBST(root->right,low,high);
        return ret;
    }
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        int ret=0;
        if (!root) return ret;
        if (root->val<=high&&root->val>=low) {
            ret+=root->val;
            ret+=rangeSumBST(root->left,low,high);
            ret+=rangeSumBST(root->right,low,high);
        }
        else if (root->val<low)
            ret+=rangeSumBST(root->right,low,high);
        else if (root->val>high)
            ret+=rangeSumBST(root->left,low,high);
        return ret;
    }
};
