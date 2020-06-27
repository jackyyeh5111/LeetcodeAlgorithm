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
class Solution {
public:
    /*
        inorder: L N R
        postorder: L R N
    */
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (inorder.size()==0&&postorder.size()==0) return 0;
        if (inorder.size()==1&&postorder.size()==1) return new TreeNode(inorder[0]);

        int node=postorder.back();
        int idx=0;
        for (;idx<inorder.size(); ++idx) {
            if(inorder[idx]==node) break;
        }
        TreeNode *root = new TreeNode(node);
        vector<int> leftIn(inorder.begin(), inorder.begin()+idx);
        vector<int> leftPost(postorder.begin(),postorder.begin()+idx);
        root->left=buildTree(leftIn,leftPost);

        vector<int> rightIn(inorder.begin()+idx+1, inorder.end());
        vector<int> rightPost(postorder.begin()+idx, postorder.end()-1);
        root->right=buildTree(rightIn,rightPost);
        return root;
    }
};
