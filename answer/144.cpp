/***** Second Visit *****/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        stack<TreeNode*> s;
        if (root) s.push(root);
        while (!s.empty()) {
            TreeNode *node=s.top(); s.pop();
            ans.push_back(node->val);
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return ans;
    }
};

/***** First Visit *****/
/************** iterative **************/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        stack<TreeNode*> s;
        if(root) s.push(root);
        while(!s.empty()) {
            TreeNode *node=s.top(); s.pop();
            ans.push_back(node->val);
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return ans;
    }
};

/************** recursive **************/
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root)
    {
        help(root);
        return ans;
    }

    void help(TreeNode *node)
    {
        if(!node) return;
        ans.push_back(node->val);
        if(node->left) help(node->left);
        if(node->right) help(node->right);
    }
};
