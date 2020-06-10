/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    void dfs(TreeNode* root, unsigned int val)
    {
        if (root)
        {
            root->val = val;
            dfs(root->left, val * 2);
            dfs(root->right, val * 2 + 1);
        }
    }

    int widthOfBinaryTree(TreeNode* root)
    {
        if (!root)
            return 0;

        dfs(root, 1);

        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(1, root));

        int ans = 1;
        while (!q.empty())
        {
            int layer = q.front().first;
            int right = 0;
            int left = 0;
            while (!q.empty() && q.front().first == layer)
            {
                if (left == 0)
                    left = q.front().second->val;
                right = q.front().second->val;

                if (q.front().second->left)
                    q.push(make_pair(layer + 1, q.front().second->left));

                if (q.front().second->right)
                    q.push(make_pair(layer + 1, q.front().second->right));

                q.pop();
            }

            ans = max(right - left + 1, ans);
        }
        return ans;
    }
};
