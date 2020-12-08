/***** Second Visit *****/
/*
    T(n)= T(n-k-1)+T(k-1)+O(1)
        <=T(n-1)
        = O(n)
    S:O(n)
*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int n=nums.size();
        return help(nums,0,n-1);
    }

    TreeNode *help(vector<int>& nums, int start, int end)
    {
        if (start>end) return 0;
        int mid=(start+end)/2;
        TreeNode *node=new TreeNode(nums[mid]);
        node->left=help(nums,start,mid-1);
        node->right=help(nums,mid+1,end);
        return node;
    }
};

/***** First Visit *****/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        /*
            height balanced BST -> start from root!
            T:O(n), S:O(n)
        */
        return help(nums,0,nums.size()-1);
    }

    TreeNode* help(vector<int> &nums, int start, int end)
    {
        if(nums.size()==0) return 0;
        if(start==end) return new TreeNode(nums[start]);
        if(start>end) return 0;
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=help(nums, start, mid-1);
        root->right=help(nums, mid+1, end);
        return root;
    }
};
