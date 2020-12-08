/***** Second Visit *****/
/*
    inorder:  [3,9,20,15,7] LNR
    preorder: [9,3,15,20,7] NLR
    Note: duplicates do not exist, or there would be multiple trees.
    T(N)= T(N-k-1)+T(k-1) + O(n)
        <=T(N-1) + O(n)
        = T:O(n^2)
    s:O(n) proportional to depth of recursive.
    -----
    recursive in terms of index rather than vector
    reduce complexity from O(n) to O(1)
    T(N)= T(N-k-1)+T(k-1) + O(1)
        <=T(N-1) + O(1)
        = T:O(n)
    s:O(n) proportional to depth of recursive.
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.size()==0&&inorder.size()==0) return 0;
        else if (preorder.size()==1&&inorder.size()==1) return new TreeNode(preorder[0]);
        int pivot=preorder[0];
        int left_size=0,right_size=0;
        while (inorder[left_size]!=pivot) left_size++;
        vector<int> left_inorder=vector<int>(inorder.begin(),inorder.begin()+left_size);
        vector<int> right_inorder=vector<int>(inorder.begin()+left_size+1,inorder.end());
        // cout<<"in:"<<left_inorder.size()<<","<<right_inorder.size()<<endl;
        vector<int> left_preorder=
            vector<int>(preorder.begin()+1,preorder.begin()+1+left_inorder.size());
        vector<int> right_preorder=vector<int>(preorder.begin()+left_inorder.size()+1, preorder.end());
        // cout<<"pre:"<<left_preorder.size()<<","<<right_preorder.size()<<endl;
        TreeNode *node=new TreeNode(pivot);
        node->left=buildTree(left_preorder,left_inorder);
        node->right=buildTree(right_preorder,right_inorder);
        return node;
    }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    }

    TreeNode* helper(vector<int>& preorder,int i,int j,vector<int>& inorder,int ii,int jj)
    {
        if(i >= j || ii >= j) return 0;
        int mid = preorder[i];
        auto f = find(inorder.begin() + ii,inorder.begin() + jj,mid);
        int dis = f - inorder.begin() - ii;
        TreeNode* root = new TreeNode(mid);
        root -> left = helper(preorder,i + 1,i + 1 + dis,inorder,ii,ii + dis);
        root -> right = helper(preorder,i + 1 + dis,j,inorder,ii + dis + 1,jj);
        return root;
    }
};

/***** First Visit *****/
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
