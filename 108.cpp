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
