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
    int count = 0;
    unordered_map<long long, int> prefix_sum;
    int pathSum(TreeNode* root, int targetSum) {
        prefix_sum[0] = 1;
        long long sum = 0;
        dfs(root, targetSum, sum);
        return count;
    }
    void dfs(TreeNode *root, int targetSum, long long sum) {
        if (!root)
            return;
        sum += root->val;
        count += prefix_sum[sum - targetSum];
        prefix_sum[sum]++;
        dfs(root->left, targetSum, sum);
        dfs(root->right, targetSum, sum);
        prefix_sum[sum]--;
    }
};
/* 
    targetSum = 3
    arr: [1 -1 1 1 1]
                 ^
    sum: 
    cnt = 1
    hashmap:
        0: 1
        10: 1
        15: 1
        18: 0
 */