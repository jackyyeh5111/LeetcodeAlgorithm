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
    void reorderList(ListNode* head)
    {
        if(!head) return;
        ListNode* tmp = head;
        rearange(&tmp, tmp);
    }

    void rearange(ListNode** head, ListNode* tail)
    {
        if (tail->next) {
            rearange(head, tail->next);
        }

        if(!(*head)) return;
        else if ((*head)->next==tail || *head ==tail) {
            tail->next=0;
            *head = 0;
            return;
        }

        ListNode* tmp = (*head)->next;
        (*head)->next = tail;
        tail->next = tmp;
        *head=tmp;

    }
};
