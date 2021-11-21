/***** Third Visit *****/
class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        bool ret=true;
        postOrder(root,ret);
        return ret;
    }
     int postOrder(TreeNode *root, bool &ret)
     {
         if (!root) return 0;
         int left=postOrder(root->left, ret);
         int right=postOrder(root->right, ret);
         if (abs(left-right)>1) ret=false;
         return max(left,right)+1;
     }
};

/***** Second Visit *****/
/*
    LRN traversal
    T:O(n)/S:O(n)
*/
class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        return getDepth(root).second;
    }

    pair<int,bool> getDepth(TreeNode *root)
    {
        if (!root) return make_pair(0,true);
        else if (!root->left&&!root->right) return make_pair(1,true);
        auto l=getDepth(root->left), r=getDepth(root->right);
        return make_pair(max(l.first,r.first)+1,(abs(l.first-r.first)<=1)&&l.second&&r.second);
    }
};

/***** First Visit *****/
class Solution {
public:
    bool ans=true;
    bool isBalanced(TreeNode* root)
    {
        getDepth(root);
        return ans;
    }

    int getDepth(TreeNode *root)
    {
        if(!root) return 0;
        int left=getDepth(root->left);
        int right=getDepth(root->right);
        if (abs(right-left)>1) { ans=false; return -1; }
        else return max(left,right)+1;
    }
};
