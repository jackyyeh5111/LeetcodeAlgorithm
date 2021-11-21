/*
    top-down NLR trav
    Notice TLE for large test case, we might have duplicate checking.
    for each node, check both left,right subtree as a root for LinkedList
    if same value of current header and root, conduct recursive func.
    WRONG ANSWER as we may involve incontiguous Linked List as well
    T(n)=4T(n-1)+O(1)=O(4^n)/S:O(n)
    ** WRONG **
    -----
    Separate contiguous checking as root from isSubPath function.
    T:O(n)/S:O(n)
*/

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root)
    {
        if (!head) return true;
        else if (!root) return false;
        bool ret=isSubPath(head, root->left)||isSubPath(head, root->right);
        if (head->val==root->val)
            ret|=help(head->next,root->left)||help(head->next,root->right);
        return ret;
    }

    bool help(ListNode* head, TreeNode* root)
    {
        if (!head) return true;
        else if (!root) return false;
        if (head->val!=root->val) return false;
        else return help(head->next,root->left)||help(head->next,root->right);
    }
};

// Wrong Anser
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root)
    {
        if (!head) return true;
        else if (!root) return false;
        bool ret=isSubPath(head, root->left)||isSubPath(head, root->right);
        if (head->val==root->val)
            ret=isSubPath(head->next,root->left)||isSubPath(head->next,root->right);
        return ret;
    }
};
