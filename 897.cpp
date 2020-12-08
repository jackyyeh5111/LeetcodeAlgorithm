/*
    in-order traverse, find predecessor of current node would take at most O(n) if we use a helper recursive function with return root node.
    T:O(n^2)/S:O(1)
    -----
    Use an additional storage for each node in increasing order.
    It would take 2 pass to construct the return tree.
    T:O(n) 2 pass/S:O(n)
    -----
    Morris traversal to keep tracking predecessor
    T:O(n)/S:O(1)
    -----
    in-order traversal with global variable to track last node.
    T:O(n)/S:O(n)
*/

// in-order with morris traversal
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root)
    {
        TreeNode *cur=root, *prev=0, *newHead=0;
        while (cur) {
            // cout<<cur->val<<endl;
            if (!cur->left) {
                // visit
                if (!newHead) {newHead=cur; prev=cur;}
                else {prev->right=cur; prev->left=0;}
                prev=cur; cur=cur->right;
            }
            else {
                TreeNode *pred=cur->left;
                while(pred->right&&pred->right!=cur) pred=pred->right;
                if (pred->right==cur) {
                    // visit
                    if (!newHead) {newHead=cur; prev=cur;}
                    else {prev->right=cur; prev->left=0;}
                    prev=cur; cur=cur->right;
                }
                else {
                    pred->right=cur;
                    cur=cur->left;
                }
            }
        }
        prev->left=0;
        return newHead;
    }
};

// in-order with call by ptr
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root)
    {
        TreeNode *head=0, *tail=0;
        inorder(root, &head, &tail);
        tail->left=0;
        return head;
    }

    void inorder(TreeNode *root, TreeNode **head, TreeNode **tail)
    {
        if (!root) return;
        inorder(root->left,head,tail);
        if (!(*head)) {*head=root; *tail=root;}
        else (*tail)->right=root;
        (*tail)->left=0;
        *tail=root;
        inorder(root->right,head,tail);
    }
};
