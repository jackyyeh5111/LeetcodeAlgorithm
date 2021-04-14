/*
    typical dfs, we can simply apply preorder traversal
    Meanwhile, maintrain current depth, max depth(deepest so far), and sum of leaves.
    T:O(n)/S:O(n) 1 pass

    Test Cases:
    []
    [1]
    [1,2]
    [1,2,3]
*/

// T:O(n)/S:O(n) iterative
class Solution {
public:
    int deepestLeavesSum(TreeNode* root)
    {
        stack<pair<TreeNode*, int>> s;
        int maxDepth=0,csum=0;
        if (root) s.push({root,0});
        while (!s.empty()) {
            auto t=s.top(); s.pop();
            if (!t.first) continue;
            else if (!t.first->left&&!t.first->right) {
                if (t.second>maxDepth) {csum=t.first->val; maxDepth=t.second;}
                else if (t.second==maxDepth) csum+=t.first->val;
            }
            else {
                s.push({t.first->left,t.second+1});
                s.push({t.first->right,t.second+1});
            }
        }
        return csum;
    }
};

// T:O(n)/S:O(n) recursive
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth=0,csum=0;
        preOrder(root,0,maxDepth,csum);
        return csum;
    }

    void preOrder(TreeNode *root, int depth, int &maxDepth, int &csum)
    {
        if (!root) return;
        if (!root->left&&!root->right) {
            if (depth==maxDepth) csum+=root->val;
            else if (depth>maxDepth) {
                csum=root->val;
                maxDepth=depth;
            }
            return;
        }
        preOrder(root->left,depth+1,maxDepth,csum);
        preOrder(root->right,depth+1,maxDepth,csum);
    }
};
