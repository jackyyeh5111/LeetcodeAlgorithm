/***** Fourth Visit *****/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return 0;
        TreeNode *left=invertTree(root->left);
        TreeNode *right=invertTree(root->right);
        root->left=right; root->right=left;
        return root;
    }
};

/***** Third Visit *****/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return 0;
        TreeNode *left=invertTree(root->left);
        TreeNode *right=invertTree(root->right);
        root->left=right; root->right=left;
        return root;
    }
};

/***** Second Visit *****/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root) return 0;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left,root->right);
        return root;
    }
};

/***** First Visit *****/
/********** recursive **********/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root) return 0;
        TreeNode *left=invertTree(root->left);
        TreeNode *right=invertTree(root->right);
        root->left=right; root->right=left;
        return root;
    }
};

/********** iterative **********/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        stack<TreeNode*> s;
        if (root) s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top(); s.pop();
            TreeNode *left=node->left;
            TreeNode *right=node->right;
            node->left=right;
            node->right=left;
            if (left) s.push(left);
            if (right) s.push(right);
        }
        return root;
    }
};
