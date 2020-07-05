/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
