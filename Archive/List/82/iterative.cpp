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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (!head) return 0;
        ListNode* r = new ListNode(0); ListNode* tail=r;
        ListNode* q=head; ListNode* p=head->next;
        while (p) {
            int count=0;
            while(p&&(q->val == p->val)) {
                p=p->next;
                count++;
                cout<<count<<endl;
            }
            if(count==0){
                tail->next=q;
                tail=tail->next;
            }

            q=p;
            if(!p) break;
            else p=p->next;

        }
        tail->next=q;
        return r->next;
    }
};
