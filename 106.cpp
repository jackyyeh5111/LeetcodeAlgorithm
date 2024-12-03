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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        return helper(inorder, postorder, 0, size - 1, 0, size - 1);
    }
    TreeNode* helper(const vector<int>& inorder, const vector<int>& postorder,
                int start_in, int end_in, int start_post, int end_post) {
        if (start_in > end_in)  return nullptr;
        if (start_in == end_in) 
            return new TreeNode(inorder[start_in]);

        TreeNode* root = new TreeNode(postorder[end_post]);
        int num_left = find(inorder.begin()+start_in, inorder.begin()+end_in, root->val) - (inorder.begin()+start_in);
        root->left = helper(inorder, postorder, start_in, start_in+num_left-1, start_post, start_post+num_left-1);
        root->right = helper(inorder, postorder, start_in+num_left+1, end_in, start_post+num_left, end_post-1);
        return root;
    }
};

/* 
      inorder = [9],3,[15,[20],7]
    postorder = [9,15,7,20,3]

    - The last element must be the root
    - Split postorder according to number elelments of lefttree and righttree
 */