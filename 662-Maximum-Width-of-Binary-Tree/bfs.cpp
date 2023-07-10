/**
    Overflow
 */
class Solution {
public:
    unordered_map<int, pair<int, int>> level_nodes;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> que;
        que.push({root, 1});
        int level = 0;

        // level order traversal
        while(!que.empty()) {
            int num_nodes = que.size();
            level_nodes[level].first = que.front().second; // leftmost
            level_nodes[level].second = que.back().second; // rightmost
            for (int i = 0; i < num_nodes; i++) {
                TreeNode* node = que.front().first;
                int id = que.front().second;
                que.pop();

                if (node->left) que.push({node->left, id * 2});
                if (node->right) que.push({node->right, id * 2 + 1});
            }
            level++;
        }

        int ans = -1;
        for (int i = 0; i < level; i++) {
            ans = max(ans, level_nodes[i].second - level_nodes[i].first + 1);
        }
        return ans;
    }
};

/* 
    level_nodes: {
        1: [leftmost node id, rightmost node id]
        2: [leftmost node id, rightmost node id]
        ...
    }

    How to define leftmost & rightmost?
        Use order id of the complete binary tree.

    node: ith
    node->left: i * 2
    node->right: i * 2 + 1
 */