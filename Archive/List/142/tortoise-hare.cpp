/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <map>
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* fast=head; ListNode* slow=head;
        do {
            if(!fast || !fast->next) return 0;
            fast=fast->next->next;
            slow=slow->next;
        }while(fast != slow);

        while(head != slow){
            head = head->next;
            slow=slow->next;
        }
        return head;
    }

    // ListNode *detectCycle(ListNode *head)
    // {
    //     map<ListNode*, bool> hashtable;
    //     while(hashtable.find(head) == hashtable.end()) {
    //         if (head) return 0;
    //         hashtable[head] = true;
    //         head = head->next;
    //     }
    //     return head;
    // }
};
