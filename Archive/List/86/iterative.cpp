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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* header = new ListNode(0);
        header->next=head;

        ListNode* tail=header;
        ListNode* smaller=header;
        ListNode* greater = new ListNode(0);
        ListNode* greaterTail = greater;
        while(tail&&tail->next){
            if (tail->next->val >= x){
                greaterTail->next = tail->next;
                greaterTail=greaterTail->next;
            }
            else{
                smaller->next=tail->next;
                smaller=smaller->next;
            }
            tail=tail->next;
        }
        smaller->next=greater->next;
        greaterTail->next=0;

        tail=header;
        header=header->next;
        delete(tail);
        delete(greater);
        return header;
    }
};
