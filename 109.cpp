/***** Second Visit *****/
/*
    1 2 3 4 5 6 7
          ^
      ^
    ^
    -----
    Binary indexing
    T(n)=2T(n/2)+O(1)
        =O(N)
    S:O(logn)
*/
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        ListNode *tail=head;
        int l=0;
        while (tail) {l++; tail=tail->next;}
        ListNode **header=&head;
        return help(0,l-1,header);
    }

    TreeNode *help(int start, int end, ListNode **node)
    {
        if (start>end) return 0;
        int mid=(start+end)/2;
        TreeNode *left = help(start,mid-1,node);
        int val=(*node)->val;
        (*node)= (*node)->next;
        TreeNode *tnode = new TreeNode (val);
        TreeNode *right = help(mid+1,end,node);
        tnode->left=left; tnode->right=right;
        return tnode;
    }
};

/***** First Visit *****/
/*
    use a hashmap to save the idx of linked list, then reduce it as sorted
    ARRAY to BST. T:O(2*n), S:O(n).
    Try another one with T:O(n), S:O(1)
        find mid node and recursive left/right part with 2 ptrs.
*/
class Solution {
public:
    // T(n)=2T(n/2)+n -> T:O(nlogn), S:O(logn)
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (!head) return 0;
        // cout<<head->val<<endl;
        if (!head->next) return new TreeNode(head->val);
        ListNode *slow=head, *fast=head, *prevSlow=0;
        while(fast&&fast->next&&fast->next->next) {
            fast=fast->next->next;
            prevSlow=slow;
            slow=slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        if (prevSlow) {
            prevSlow->next=0;
            root->left=sortedListToBST(head);
            root->right=sortedListToBST(slow->next);
        }
        else if (slow->next) {
            root->right=new TreeNode(slow->next->val);
        }
        return root;
    }
};

class Solution {
public:
    // T:O(n), S:O(logn)
    ListNode *header;
    TreeNode* sortedListToBST(ListNode* head)
    {
        header=head;
        int size=0;
        while(head) { size++; head=head->next; }

        return help(0,size-1);
    }

    // Act like inorder traversal.
    TreeNode* help(int l, int r)
    {
        if(l>r) return 0;
        int mid=(l+r)/2;
        TreeNode *left=help(l,mid-1);
        TreeNode *root = new TreeNode(header->val);
        header=header->next;
        TreeNode *right=help(mid+1,r);
        root->left=left; root->right=right;
        return root;
    }
};
