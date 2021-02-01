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