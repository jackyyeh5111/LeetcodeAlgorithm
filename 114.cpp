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
/***************** recursive *****************/
class Solution {
public:
    void flatten(TreeNode* root)
    {
        /*
            Look at the example, we can find that flatten tree is equal to the order of
            preorder traversal, and collect each node to the right part.
            Thus, think about preorder.
                Each time we visit the node in recursive step, check left part first
                TreeNode *right=flatten(root->right);
                TreeNode *left=flatten(root->left);
                root->right=left;
                while(root->right)root=root->right;
                root->right=right;
            How about end condition?
            Each time we reach leaf, i.e. a node without children, return it.
        */
        if (!root) return;
        if (!root->left&&!root->right) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *tail=root, *right=root->right;
        root->right=root->left;
        root->left=0;
        while(tail&&tail->right) tail=tail->right;
        tail->right=right;
    }
};

/***************** iterative *****************/
class Solution {
public:
    void flatten(TreeNode *root) {
		TreeNode*now = root;
		while (now)
		{
			if(now->left)
			{
                //Find current node's prenode that links to current node's right subtree
				TreeNode* pre = now->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = now->right;
                //Use current node's left subtree to replace its right subtree(original right
                //subtree is already linked by current node's prenode
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
    }
};
