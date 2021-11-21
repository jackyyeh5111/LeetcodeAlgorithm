/***** Second Visit *****/
/*
    [4,1,3,null,null,2], val=5

    append to the last position

    construcc: LNR, N is the largest
    if val < N, go right
    else if val > N:  val->left=N

    preorder traversal
    T:O(n)/S:O(n)
*/

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val)
    {
        if (!root) return new TreeNode(val);
        else if (val>root->val) {
            TreeNode *node=new TreeNode(val);
            node->left=root;
            return node;
        }
        else {
            root->right=insertIntoMaxTree(root->right,val);
            return root;
        }
    }
};

/***** First Visit *****/
/*
    As description, we know the tree is constructed in in-order.
    Thus the appended val will always go right.
    Start from root node and always visiit right child.
    If the node's val less than target val, swap them.
    T:O(H), worst: T:O(n)/S:O(1)
    edge: our target val is larger than root->val, use header node as sanity check.

    1 4 2 3 5 0
*/
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val)
    {
        if (!root||val>root->val) {
            TreeNode *head=new TreeNode(val);
            head->left=root;
            return head;
        }
        TreeNode *cur=root;
        while (cur->right&&cur->right->val>val) cur=cur->right;
        if (!cur->right) cur->right=new TreeNode(val);
        else {
            TreeNode *next=cur->right;
            cur->right=new TreeNode(val);
            cur->right->left=next;
        }
        return root;
    }
};
