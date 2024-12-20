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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // 1) build graph
        unordered_map<TreeNode*, TreeNode*> parents;
        parents[root] = nullptr;
        buildGraph(parents, root);

        // 2) bfs
        vector<int> ans;
        bfs(parents, target, k, ans);
        return ans;
    }
    void bfs(const unordered_map<TreeNode*, TreeNode*>& parents, TreeNode* target, int k, vector<int>& ans) {
        queue<TreeNode*> que;
        que.push(target);

        unordered_set<TreeNode*> visited;
        while(!que.empty()) {
            int numLevel = que.size();
            for (int i = 0; i < numLevel; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (!node || visited.count(node)) continue;
                visited.insert(node);

                if (k == 0) {
                    ans.push_back(node->val);
                }
                que.push(parents.at(node));
                que.push(node->left);
                que.push(node->right);
            }
            k--;
            
            if (k < 0) break;
        }

    }
    void buildGraph(unordered_map<TreeNode*, TreeNode*>& parents, TreeNode* node) {
        if (!node) return;
        if (node->left) {
            parents[node->left] = node;
            buildGraph(parents, node->left);
        }
        if (node->right) {
            parents[node->right] = node;
            buildGraph(parents, node->right);
        }
    }
};