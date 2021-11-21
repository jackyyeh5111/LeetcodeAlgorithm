/*
    encode it through post order traversal
    T:O(n)/S:O(n)
*/
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
         vector<TreeNode*> ans;
         unordered_map<string,pair<TreeNode*,bool>> m;
         postOrder(root,m,ans);
         return ans;
    }

    string postOrder(TreeNode *root, unordered_map<string,pair<TreeNode*,bool>> &m, vector<TreeNode*> &ans)
    {
        if (!root) return "n";
        string left=postOrder(root->left, m, ans);
        string right=postOrder(root->right, m, ans);
        string encode=left+"_"+right+"_"+to_string(root->val);
        if (m.count(encode)!=0&&m[encode].second==false){
            ans.push_back(m[encode].first);
            m[encode].second=true;
        }
        else if (m.count(encode)==0) m[encode]={root,false};
        return encode;
    }
};
