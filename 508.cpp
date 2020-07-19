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
    unordered_map<int,int> m;
    int max_frequency=0;
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        help(root);
        // m is compiled with k:sum v:frequency
        vector<int> ans;
        // process
        for (auto it=m.begin(); it!=m.end(); ++it) {
		    if(it->second==max_frequency)
                ans.push_back(it->first);
	    }
	    return ans;
    }

    int help(TreeNode *root)
    {
        if(!root) return 0;
        int left=help(root->left);
        int right=help(root->right);
        int sum=left+right+root->val;
        m[sum]++;
        max_frequency=max(max_frequency,m[sum]);
        return sum;
    }
};
