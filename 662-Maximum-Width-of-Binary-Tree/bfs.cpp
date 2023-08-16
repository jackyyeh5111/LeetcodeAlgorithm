/* 
    pass. Use long long and minus first_id.
 */
class Solution2 {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        
        // bfs traversal
        queue<pair<TreeNode*, long long>> que;
        que.push({root, 1});
        
        while(!que.empty()) {
            long long width = que.back().second - que.front().second + 1;
            ans = max(ans, (int)width);
            int num_level = que.size();
            long long first_id = -1;
            for (int i = 0; i < num_level; i++) {
                TreeNode* node = que.front().first;
                long long id = que.front().second;
                que.pop();
                if (node->left) {
                    if (first_id == -1)
                        first_id = id * 2;
                    que.push({node->left, id * 2 - first_id}); // minus first_id
                }
                if (node->right) {
                    if (first_id == -1)
                        first_id = id * 2 + 1;
                    que.push({node->right, id * 2 + 1 - first_id}); // minus first_id
                }
            }
        }
        return ans;
    }
};


/**
    Overflow
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        
        // bfs traversal
        queue<pair<TreeNode*, int>> que;
        que.push({root, 1});
        
        while(!que.empty()) {
            int width = que.back().second - que.front().second + 1;
            ans = max(ans, width);
            int num_level = que.size();
            for (int i = 0; i < num_level; i++) {
                TreeNode* node = que.front().first;
                int id = que.front().second;
                que.pop();
                if (node->left)
                    que.push({node->left, id * 2});
                if (node->right)
                    que.push({node->right, id * 2 + 1});
            }
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