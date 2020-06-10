/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode* header = new ListNode(0);
        header->next=head;
        ListNode* tail=header;
        while(m>1){
            tail=tail->next;
            m--;
            n--;
        }
        ListNode* record=tail->next;
        ListNode* p=tail->next; ListNode* q=p->next;
        for (int i=0; i<n-m;++i){
            ListNode* tmp=q->next;
            q->next = p;
            p=q; q=tmp;
        }
        tail->next=p;
        record->next=q;
        ListNode* tmp=header;
        header=header->next;
        delete(tmp);
        return header;
    }

};
