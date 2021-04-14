/***** Second Visit *****/
/*
    Greater tree is to change the original key plus sum of all keys greater than the original key in BST.
    This indicates to traverse in RNL, which is inverse inorder.

    T:O(n)/S:O(n)
*/
class Solution {
public:
    int csum=0;
    TreeNode* convertBST(TreeNode* root)
    {
        if (!root) return 0;
        convertBST(root->right);
        csum+=root->val;
        root->val=csum;
        convertBST(root->left);
        return root;
    }
};

/***** First Visit *****/
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
