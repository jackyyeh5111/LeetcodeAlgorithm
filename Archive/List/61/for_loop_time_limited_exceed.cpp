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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* tail=head; ListNode* newTail;
        for(int i=0; i<k; ++i){
            while(tail->next){
                newTail=tail;
                tail=tail->next;
            }
            tail->next=head;
            newTail->next=0;
            head=tail;
        }
        return head;
    }
};
