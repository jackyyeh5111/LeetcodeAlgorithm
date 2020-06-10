/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        vector<string> result_vector = traverse(root);
        cout<<result_vector.size()<<endl;
        string min_result = result_vector[0];
        for(int i=1; i<result_vector.size(); ++i){
            cout<<result_vector[i]<<endl;
            if(result_vector[i]<min_result) min_result = result_vector[i];
        }
        return min_result;
    }

    vector<string> traverse(TreeNode* root)
    {
        vector<string> result;
        if(!root) return result;
        if (!root->right&&!root->left) {
            result.push_back(string(1,'a'+root->val));
            return result;
        }
        if (root->right){
            vector<string> right_vector = traverse(root->right);
            for(string& str : right_vector) str += string(1,'a'+root->val);
            result.insert(result.end(), right_vector.begin(), right_vector.end());
        }
        if (root->left){
            vector<string> left_vector = traverse(root->left);
            for(string& str : left_vector) str += string(1,'a'+root->val);
            result.insert(result.end(), left_vector.begin(), left_vector.end());
        }

        return result;
    }
};
