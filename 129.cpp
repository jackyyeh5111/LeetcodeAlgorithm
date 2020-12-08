/***** Third Visit *****/
 /*
     dfs, NLR, preorder traversal
     T:O(n)/S:O(n)
 */
 class Solution {
 public:
     int sumNumbers(TreeNode* root) {
         int ans=0;
         help(root,0,ans);
         return ans;
     }

     void help(TreeNode *root, int val, int &ans)
     {
         if (!root) return;
         val=val*10+root->val;
         if (!root->left&&!root->right) {
             ans+=val;
             return;
         }
         help(root->left,val,ans);
         help(root->right,val,ans);
     }
 };

/***** Second Visit *****/
class Solution {
public:
    int ans=0;
    int sumNumbers(TreeNode* root)
    {
        /*
            use a help function for NLR traversal, each time reach leaf, sum it
            to the ans. Notice that if there's overflow or not.
        */
        help(root,0);
        return ans;
    }

    void help(TreeNode* root, int sum)
    {
        if (!root) return;
        sum = sum*10 + root->val;
        if(!root->left&&!root->right) {ans+=sum; return;}
        help(root->left,sum);
        help(root->right,sum);
    }
};

/***** First Visit *****/
 // T:O(n), S:O(logN)
class Solution {
public:
    int sum=0;
    int sumNumbers(TreeNode* root)
    {
        help(root,0);
        return sum;
    }

    void help(TreeNode *root, int val)
    {
        if (!root) return;
        val=val*10+root->val;
        if(!root->left&&!root->right) sum+=val;
        else {
            help(root->left,val);
            help(root->right,val);
        }
    }
};
