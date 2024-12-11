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
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(root);
        vector<int> ans;
        unordered_set<TreeNode*> visited;
        dfs(target, k, ans, visited);
        return ans;
    }
    void dfs(TreeNode* node, int k, vector<int> &ans, unordered_set<TreeNode*> &visited) {
        if (!node) return;
        if (visited.count(node)) return;
        visited.insert(node);
        if (k == 0) {
            ans.push_back(node->val);
            return;
        }
        for (auto& next_node : graph[node]) {
            dfs(next_node, k-1, ans, visited);
        }

    }
    void buildGraph(TreeNode* node) {
        if (!node) return;
        if (node->left) {
            graph[node].push_back(node->left);
            graph[node->left].push_back(node);
            buildGraph(node->left);
        }
        if (node->right) {
            graph[node].push_back(node->right);
            graph[node->right].push_back(node);
            buildGraph(node->right);
        }
    }

};