/***** Second Visit *****/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> ans;
        help(root,ans,"");
        return ans;
    }

    void help(TreeNode *root, vector<string> &ans, string path)
    {
        if (!root) return;
        path+=to_string(root->val);
        if (!root->left&&!root->right) ans.push_back(path);
        else {
            path+="->";
            help(root->left,ans,path);
            help(root->right,ans,path);
        }
    }
};

/***** First Visit *****/
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
