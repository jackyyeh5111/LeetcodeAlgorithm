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

/****************** Second Visit ******************/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        /*
            inorder: LNR
            postorder: LRN
            T(n)=T(1)+T(n-1)+O(n) -> n+n-1+...+1=O(n^2)
            -------
            We could use hashmap to reduce finding from O(n) to O(1)
            Thus, time complexity would be T:O(n)
        */
        int n=inorder.size();
        if (n==1) return new TreeNode(inorder[0]);
        else if (n==0) return 0;

        TreeNode *root=new TreeNode(postorder.back());
        int i=0; while (inorder[i]!=root->val) i++;
        vector<int> leftInorder(inorder.begin(),inorder.begin()+i);
        vector<int> leftPostorder(postorder.begin(),postorder.begin()+i);
        vector<int> rightInorder(inorder.begin()+i+1,inorder.end());
        vector<int> rightPostorder(postorder.begin()+i,postorder.end()-1);
        TreeNode *left=buildTree(leftInorder,leftPostorder);
        TreeNode *right=buildTree(rightInorder,rightPostorder);
        root->left=left; root->right=right;
        return root;
    }
};

/****************** First Visit ******************/
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
