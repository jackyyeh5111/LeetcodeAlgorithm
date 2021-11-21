/***** Second Visit *****/
/*
    fast/slow ptr.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *fast=head,*slow=head, *a=0;
        for (int i=1; i<k; ++i) fast=fast->next;
        a=fast;
        while (fast->next) {
            fast=fast->next;
            slow=slow->next;
        }
        swap(a->val,slow->val);
        return head;
    }
};

/***** First Visit *****/
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode *cur=head;
        for (int i=1; i<k; ++i) cur=cur->next;
        ListNode *a=cur;
        ListNode *b=head;
        while(cur->next) {
            b=b->next;
            cur=cur->next;
        }
        swap(a->val,b->val);
        return head;
    }
};
