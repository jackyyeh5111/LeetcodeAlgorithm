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
    // T:O(n^2) S:O(logN)
    // Time: each root is searched in inorder, thus we have n+n-1+n-2+...+1
    //       comparison times, which is O(n^2)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        /*
            preorder+inorder->unique tree if no duplicated number
        */
        if (preorder.size()==0&&inorder.size()==0) return 0;
        if (preorder.size()==1&&inorder.size()==1) return new TreeNode(inorder[0]);
        int node=preorder[0];
        int idx=0;
        for (;idx<inorder.size(); ++idx){
            if (inorder[idx]==node) break;
        }
        TreeNode *root = new TreeNode(node);
        vector<int> leftPre(preorder.begin()+1,preorder.begin()+1+idx);
        vector<int> leftIn(inorder.begin(),inorder.begin()+idx);
        root->left=buildTree(leftPre,leftIn);

        vector<int> rightPre(preorder.begin()+1+idx,preorder.end());
        vector<int> rightIn(inorder.begin()+idx+1,inorder.end());
        root->right=buildTree(rightPre,rightIn);
        return root;
    }
};
