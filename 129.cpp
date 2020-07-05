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
/******************* Second Visit **********************/
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

/******************* First Visit **********************/
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
