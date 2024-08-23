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
    unordered_map<TreeNode*, TreeNode*> parents;
    unordered_set<TreeNode*> visited;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        createParents(root, nullptr);
        
        vector<int> ans;
        dfs(target, parents, k, ans);
        return ans;
    }
    void dfs(TreeNode* node, const unordered_map<TreeNode*, TreeNode*> &parents, int k, vector<int> &ans) {
        if (!node || visited.count(node)) // root's parent is nullptr
            return;
        
        visited.insert(node);
        if (k == 0) {
            ans.push_back(node->val);
            return;
        }
        dfs(node->left, parents, k-1, ans);
        dfs(node->right, parents, k-1, ans);
        dfs(parents.at(node), parents, k-1, ans);
    }
    void createParents(TreeNode* node, TreeNode *parent) {
        if (!node)
            return;
        parents[node] = parent;
        createParents(node->left, node);
        createParents(node->right, node);
    }
};

/* 
    1) Find parents for each node (using hashmap)
    2) dfs from target node (three edges => left child, right child, parent)
 
    parents: // hashmap
        3 -> None
        5 -> 3
        1 -> 3
        ...
 */