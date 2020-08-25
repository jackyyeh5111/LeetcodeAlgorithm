/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  * };
  */
/******************* Second Visit *******************/
/* early stop, T:O(n/2), S:O(n) */
 class Solution {
 public:

     int countNodes(TreeNode* root)
     {
         /*
             recursive dfs can make it T:O(n), maybe overflow or TLE.
         */
         if(!root) return 0;
         int depth=0;
         TreeNode *cur=root;
         while(cur->left) {depth++; cur=cur->left;}
         int leaf=0;
         help(root,0,depth,leaf);
         // cout<<leaf<<endl;
         return pow(2,depth)-1+leaf;
     }

     bool help(TreeNode* root, int depth, int max_depth, int &leaf)
     {
         if (!root) return false;
         // cout<<depth<<endl;
         if (depth==max_depth) { leaf++; return true; }
         if (!help(root->left,depth+1,max_depth,leaf)||!help(root->right,depth+1,max_depth,leaf))
             return false;
         else return true;
     }
 };

/******************* First Visit *******************/
class Solution {
public:
    int countNodes(TreeNode* root)
    {
        /*
            if (0) return 0
            count
            if (left) count+=countNodes(left)
            if (right) count+=countNodes(right)
            -----------------
            recursive preorder/inorder/postorder, T:O(n), S:O(logn) in average
            recursive interms of DEPTH:
            T(n)=T(n/2)+2*logn
            -> master theorem case 3: O((logn)^2)
        */

        if(!root) return 0;
        int leftD=getDepth(root->left);
        int rightD=getDepth(root->right);
        if (leftD==rightD)
            return (1<<leftD)+countNodes(root->right);
        else
            return (1<<rightD)+countNodes(root->left);
    }

    int getDepth(TreeNode *root)
    {
        if (!root) return 0;
        return 1+getDepth(root->left);
    }
};
