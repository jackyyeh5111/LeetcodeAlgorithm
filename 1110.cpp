/***** First Visit *****/
/*
    preorder: T:O(n)/S:O(n)
    -----
    postorder: T:O(n)/S:O(n)
*/

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        vector<TreeNode*> ans;
        unordered_set<int> delete_set(to_delete.begin(),to_delete.end());
        help(root, delete_set, ans, true);
        return ans;
    }

    void help(TreeNode *root, unordered_set<int> delete_set, vector<TreeNode*> &ans, bool is_root)
    {
        if (!root) return;
        if (is_root&&delete_set.count(root->val)==0) {
            ans.push_back(root);
            is_root=false;
        }

        TreeNode *left=root->left;
        TreeNode *right=root->right;
        bool is_left_root=is_root, is_right_root=is_root;
        if (left&&delete_set.count(left->val)!=0) {
            root->left=0; is_left_root=true;
        }
        if (right&&delete_set.count(right->val)!=0) {
            root->right=0; is_right_root=true;
        }
        help(left,delete_set,ans,is_left_root);
        help(right,delete_set,ans,is_right_root);
    }
};

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        vector<TreeNode*> ans;
        unordered_set<int> delete_set(to_delete.begin(),to_delete.end());
        help(root,delete_set,ans);
        if (root&&delete_set.count(root->val)==0) ans.push_back(root);
        return ans;
    }

    bool help(TreeNode* root, unordered_set<int> delete_set, vector<TreeNode*> &ans)
    {
        if (!root) return false;
        TreeNode *left=root->left, *right=root->right;
        if (help(left,delete_set,ans)) root->left=0;
        if (help(right,delete_set,ans)) root->right=0;
        bool should_delete = false;
        if (delete_set.count(root->val)!=0) {
            should_delete = true;
            if (left&&delete_set.count(left->val)==0) ans.push_back(left);
            if (right&&delete_set.count(right->val)==0) ans.push_back(right);
        }
        return should_delete;
    }
};
