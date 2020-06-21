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
    // T:O(n), S:O(1)
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        /*
                .   .
            h 1 2 3 4 5 m=2,n=4
              p ^
        */
        if (!head||m==n) return head;
        ListNode *header = new ListNode(0);
        header->next=head;
        ListNode *p=header;

        int pos=0;
        while(pos<m-1) {p=p->next; pos++;}
        pos++; ListNode* q=p->next; ListNode *r=q->next; ListNode *t=0;
        cout<<pos<<endl;
        while(pos<n) {
            t=r->next;
            r->next=q; q=r; r=t;
            pos++;
        }
        t = p->next; p->next=q; t->next=r;
        return header->next;

    }
};
