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

 /***** Second Visit *****/
 /*
    Linked List:
    1. header (V)
    2. slow/fast ptr.
    T: one pass O(n)/S:O(1)
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode *header=new ListNode();
        header->next=head;
        ListNode *cur=head,*prev=header;
        for (int i=1; i<m; ++i) {prev=cur; cur=cur->next;}
        ListNode *p=0;
        for (int i=m; i<=n; ++i) {
            ListNode *next=cur->next;
            cur->next=p;
            p=cur; cur=next;
        }
        prev->next->next=cur;
        prev->next=p;
        return header->next;
    }
};

 /***** First Visit *****/
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
