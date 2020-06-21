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
class Solution {
public:
    // T:O(n)
    ListNode* partition(ListNode* head, int x)
    {
        /*
        2 pointers, say smaller, larger
        smaller->next=larger
        try to do it in one pass
        */
        ListNode *s = new ListNode(0); // smaller
        ListNode *l = new ListNode(0); // larger
        ListNode *st=s,*lt=l;

        while(head) {
            if (head->val<x) {st->next=head; st=st->next;}
            else {lt->next=head; lt=lt->next;}
            head=head->next;
        }
        st->next=l->next;
        lt->next=0;
        lt=s; s=s->next;
        delete(lt); delete(l);
        return s;
    }
};
