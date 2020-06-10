/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
private:
    std::vector<TreeNode*> nodes;
public:
    // O(N)
    CBTInserter(TreeNode* root) {
        if(!root) return;
        std::queue<TreeNode*> node_queue;
        node_queue.push(root);
        while(!node_queue.empty()){
            TreeNode* node = node_queue.front();
            node_queue.pop();
            nodes.push_back(node);
            if(node->left) node_queue.push(node->left);
            if(node->right) node_queue.push(node->right);
        }
    }

    // O(1)
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        nodes.push_back(node);
        TreeNode* parent = nodes[(nodes.size()-2)/2];
        if((nodes.size()-1)%2==0) parent->right = node;
        else parent->left = node;
        return parent->val;
    }

    // O(1)
    TreeNode* get_root() {
        return nodes[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

 // THINK: use O(nleaf) for spatial complexity.
 // save only nodes whose degree is under two (do not have 2 children)
