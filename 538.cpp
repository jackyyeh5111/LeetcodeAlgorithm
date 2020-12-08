class Solution {
public:
    TreeNode* convertBST(TreeNode* root)
    {
        stack<pair<TreeNode*,bool>> s;
        if (root) s.push(make_pair(root,false));
        int cur_sum=0;
        while (!s.empty()) {
            auto node=s.top(); s.pop();
            if (node.second) {
                cur_sum+=(node.first)->val;
                (node.first)->val=cur_sum;
            }
            else {  // inv-inorder RNL <-
                if ((node.first)->left)
                    s.push(make_pair((node.first)->left,false));
                s.push(make_pair(node.first,true));
                if ((node.first)->right)
                    s.push(make_pair((node.first)->right,false));
            }
        }
        return root;
    }
};
