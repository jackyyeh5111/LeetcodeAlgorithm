/* 
    More elegant with pointer to pointer
 */
class Solution2 {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        
        queue<TreeNode**> que;
        que.push(&root);
        
        vector<TreeNode*> ans;
        if (st.find(root->val) == st.end())
            ans.push_back(root);

        while(!que.empty()) {
            TreeNode** node_ptr = que.front();
            TreeNode* node = *node_ptr;
            que.pop();
            
            if (node->left)
                que.push(&node->left);
            if (node->right)
                que.push(&node->right);

            if (st.find(node->val) != st.end()) {
                if (node->left && st.find(node->left->val) == st.end())
                    ans.push_back(node->left);
                if (node->right && st.find(node->right->val) == st.end())
                    ans.push_back(node->right);
                *node_ptr = nullptr;
            }
        }
        return ans;
    }
};

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        
        queue<TreeNode*> que;
        que.push(root);
        
        vector<TreeNode*> ans;
        if (to_delete_set.find(root->val) == to_delete_set.end())
            ans.push_back(root);

        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            
            bool is_cur_delete = to_delete_set.find(node->val) != to_delete_set.end();
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            if (left) {
                que.push(left);
                bool is_left_delete = to_delete_set.find(left->val) != to_delete_set.end();
                if (is_cur_delete && !is_left_delete) {
                    ans.push_back(left);
                }
                if (is_left_delete)
                    node->left = nullptr;
            }
            if (node->right) {
                que.push(node->right);
                bool is_right_delete = to_delete_set.find(node->right->val) != to_delete_set.end();
                if (is_cur_delete && !is_right_delete) {
                    ans.push_back(node->right);
                }
                if (is_right_delete)
                    node->right = nullptr;
            }
        }
        return ans;
    }
};

/* 
    Clarification:
        1. node's value are distinct
        2. tree representation
        3. Ignore value in to_delete if it does not exist in tree
    
    (T) rep1: 1 2 null 3
    (F) rep2: 1 2 null 3 null
        1
       /
      2 
    /
   3

    Problem:
        1. When to add the node into the output?
            Parent node is deleted, and current node is not.
        2. How to delete a node
            2.1 If node has children, we have to record children first.
            2.2 Replace the node with a nullptr.

    3 stes:
        1. check if left, right child nullptr. If not, 

    case 1:
        to_delete: [3, 5]
        to_delete : {
            3: true 
            5: true
        }

        // vector<TreeNode*>
        ans: [1, 6, 7]
        
        // queue<pair<parent_TreeNode*, child_TreeNode*>>
        queue: []
 */





