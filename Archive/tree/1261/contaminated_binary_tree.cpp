/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    TreeNode* tree;

    FindElements(TreeNode* root) {
        tree = traverse(root, 0);
    }

    TreeNode* traverse(TreeNode* root, int value)
    {
        if(!root) return 0;
        root->val = value;
        traverse(root->left, value*2+1);
        traverse(root->right, value*2+2);
        return root;
    }

    bool find(int target) {
        return find_(target, tree);
    }

    bool find_(int target, TreeNode* node) {
        if (!node) return false;
        return target==node->val || find_(target, node->left) || find_(target, node->right);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
