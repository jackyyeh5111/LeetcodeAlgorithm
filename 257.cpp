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
    vector<string> paths;
    vector<string> binaryTreePaths(TreeNode* root)
    {
        if(!root) return paths;
        vector<int> path;
        help(root,path);
        return paths;
    }

    void help(TreeNode *root, vector<int> &path)
    {
        path.push_back(root->val);
        if (!root->left&&!root->right){
            string str="";
            for (int i=0; i<path.size()-1; ++i) {
                str += to_string(path[i]);
                str += "->";
            }
            str+=to_string(path.back());
            paths.push_back(str);
        }
        if (root->left) help(root->left, path);
        if (root->right) help(root->right, path);
        path.pop_back();
    }
};
