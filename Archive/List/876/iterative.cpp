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
    /*
    ListNode* middleNode(ListNode* head) {
        if(!head) return head;
        vector<ListNode*> list;
        int idx = 0;
        while(head) {
            list.push_back(head);
            idx++;
            head = head->next;
        }
        return list[idx/2];
    }
    */
    ListNode* middleNode(ListNode* head) {
        ListNode* t1=head;
        ListNode* t2=head;
        for(;t2&&t2->next;t2=t2->next->next){t1 = t1->next;}
        return t1;
    }


};
