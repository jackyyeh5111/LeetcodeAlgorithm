/***** Second Visit *****/
class Solution {
public:
    int pathSum(TreeNode* root, int sum)
    {
        if (!root) return 0;
        return pathSum(root->left,sum)+pathSum(root->right,sum)+help(root,sum);
    }

    int help(TreeNode *root, int sum)
    {
        if (!root) return 0;
        return (root->val==sum)+help(root->left,sum-root->val)+help(root->right,sum-root->val);
    }
};

/***** First Visit *****/
/*
    Use preorder traversal to traverse each node with a current sum
    if its equal to target, then plus one
    ------
    add sum may meet overflow, start from sum and detect
    ------
    above is wrong thought, path maynot start from root, if we treat each node as root and do
    traversal, time complexity woule be T:O(n^2) in worst case, furthermore, value could be negative.
    ======
    use a preorder traversal with a set to record each path from root to leaf, and search current sum-
    target sum.
    S:O(logn ^ 2), T:O(n)
    0 1 3 6 10 10 8

    0 0
    8  8
    0 -8
    8   8
    0    -8
    8      8
*/

/*********** Recursive with worst case T:O(n^2) ***********/
class Solution {
public:
    int pathSum(TreeNode* root, int sum)
    {
        if(!root) return 0;
        return pathSum(root->left,sum)+pathSum(root->right,sum)+help(root,sum);
    }

    int help(TreeNode* root, int sum)
    {
        if (!root) return 0;
        return (root->val==sum) + help(root->left,sum-root->val)
                                + help(root->right,sum-root->val);
    }
};

/*********** Recursive with worst case T:O(n) + hashmap ***********/
class Solution {
public:
    int ans=0;
    int pathSum(TreeNode* root, int sum)
    {
        unordered_map<int,int> m; m[0]=1;
        help(root,m,0,sum);
        return ans;
    }

    void help(TreeNode* root, unordered_map<int,int> &path_sum, int cur, int target)
    {
        if (!root) return;
        cur+=root->val;
        if (path_sum.find(cur-target)!=path_sum.end()) ans += path_sum[cur-target];
        path_sum[cur]++;
        help(root->left, path_sum, cur, target);
        help(root->right, path_sum, cur, target);
        path_sum[cur]--;
    }
};
