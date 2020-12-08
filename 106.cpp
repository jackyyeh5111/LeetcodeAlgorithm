/***** First Visit *****/
/*
    LNR v.s. LRN
    T(n)= T(n-k-1)+T(k-1)+O(n)
        <=T(n-1)+O(n)
        = O(n^2)
    S: O(n)
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int n=inorder.size();
        if (n==0) return 0;
        else if (n==1) return new TreeNode(inorder[0]);
        TreeNode *node=new TreeNode(postorder.back());
        int i=0; while(inorder[i]!=node->val) i++;
        vector<int> l_inorder(inorder.begin(),inorder.begin()+i);
        vector<int> r_inorder(inorder.begin()+i+1,inorder.end());
        vector<int> l_postorder(postorder.begin(),postorder.begin()+i);
        vector<int> r_postorder(postorder.begin()+i,postorder.end()-1);
        node->left=buildTree(l_inorder,l_postorder);
        node->right=buildTree(r_inorder,r_postorder);
        return node;
    }
};

/***** Second Visit *****/
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

/***** First Visit *****/
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
