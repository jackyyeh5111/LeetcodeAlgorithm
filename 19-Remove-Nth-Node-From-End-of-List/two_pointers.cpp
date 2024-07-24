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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = &dummy;
        for (int i = 0; i < n; i++)
            cur = cur->next;

        while(cur->next) {
            prev = prev->next;
            cur = cur->next;
        }
        prev->next = prev->next->next;
        return dummy.next;
    }
};

/* 
    [1], n = 1

    D -> 1 -> 2
    p
              c

    D -> 1 -> 2 -> 3 (n=2)
         p
                   c
    
    D -> 1 -> 2 -> 3 (n=3)
    p
                   c

    D -> 1 (n=1)
    p
         c
*/