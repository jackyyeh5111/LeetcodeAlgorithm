/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // Worst Case: O(N^2)
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size()==0) return 0;
        if (nums.size()==1) return new TreeNode(nums[0]);
        int max_num = 0;
        int max_id = 0;
        for(int i=0; i<nums.size(); ++i){
            if (nums[i]<=max_num) continue;
            max_num = nums[i];
            max_id = i;
        }
        vector<int> left_vector = vector<int>(nums.begin(),nums.begin()+max_id);
        TreeNode* left = constructMaximumBinaryTree(left_vector);
        vector<int> right_vector = vector<int>(nums.begin()+max_id+1,nums.end());
        TreeNode* right = constructMaximumBinaryTree(right_vector);
        TreeNode* root = new TreeNode(nums[max_id]);
        root->left = left;
        root->right = right;
        return root;

    }
};

// Worst Case: O(NlogN)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for (int i = 0; i < nums.size(); ++i)
        {
            TreeNode* cur = new TreeNode(nums[i]);
            while (!stk.empty() && stk.back()->val < nums[i])
            {
                cur->left = stk.back();
                stk.pop_back();
            }
            if (!stk.empty())
                stk.back()->right = cur;
            stk.push_back(cur);
        }
        return stk.front();
    }
};
