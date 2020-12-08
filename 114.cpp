/***** Second Visit *****/
/*
    Top-down solution
    LRN postorder traversal.
    stop criteria: leaf node
    T:O(n)/S:O(n)
    -----
    iteratively merge left subtree.
        1
       / \
      2   5
     / \   \
    3   4   6

        1
         \
          2
         / \
        3   4
             \
              5
               \
                6
    ...
    T:O(n)/S:O(1)
    -----
    Bottom-up solution
    We can see the example is to make the right tree as preorder.
    We can do it bottom up by inversing the traverse order.
    NLR->RLN
    Use a prev node to record the latest we are reaching from bottom.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    void flatten(TreeNode* root)
    {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *left=root->left, *right=root->right;
        if (left) {
            root->right=left;
            while(root&&root->right) {
                root->left=0;
                root=root->right;
            }
        }
        root->right=right;
    }
};

class Solution {
public:
    void flatten(TreeNode* root)
    {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *pred=cur->left;
                while(pred->right) pred=pred->right;
                pred->right=cur->right;
                cur->right=cur->left;
                cur->left=0;
            }
            cur=cur->right;
        }
    }
};

class Solution {
public:
    TreeNode *prev=0;
    void flatten(TreeNode* root)
    {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=0;
        prev=root;
    }
};

/***** First Visit *****/
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
		TreeNode *now = root;
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
