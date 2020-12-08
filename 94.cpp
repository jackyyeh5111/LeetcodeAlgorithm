 /***** Second Visit *****/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        stack<pair<TreeNode*,bool>> s;
        if (root) s.push(make_pair(root,false));
        while (!s.empty()) {
            auto p=s.top(); s.pop();
            if (p.second) ans.push_back((p.first)->val);
            else {
                if ((p.first)->right) s.push(make_pair((p.first)->right,false));
                s.push(make_pair((p.first),true));
                if ((p.first)->left) s.push(make_pair((p.first)->left,false));
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root)
    {
        help(root);
        return ans;
    }
    void help(TreeNode *node)
    {
        if (!node) return;
        help(node->left);
        ans.push_back(node->val);
        help(node->right);
    }
};

 /***** First Visit *****/
 class Solution {
 public:
     // iterative T:O(n), S:O(n)
     vector<int> ans;
     vector<int> inorderTraversal(TreeNode* root) {
         stack<pair<TreeNode*,bool>> s;
         if (root) s.push(make_pair(root,false));
         while(!s.empty()){
             auto p=s.top(); s.pop();
             if (p.second) ans.push_back(p.first->val);
             else {
                 if (p.first->right) s.push(make_pair(p.first->right,false));
                 p.second=true; s.push(p);
                 if (p.first->left) s.push(make_pair(p.first->left,false));
             }
         }
         return ans;
     }
 };

class Solution {
public:
    // recursive T:O(n), S:O(logn) average height
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* root)
    {
        if (!root) return;
        if (root->left) inorder(root->left);
        ans.push_back(root->val);
        if (root->right) inorder(root->right);
    }
};
