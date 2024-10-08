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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA;
        while(ptrA) {
            ListNode* ptrB = headB;
            while(ptrB) {
                if (ptrA == ptrB)
                    return ptrA;
                ptrB = ptrB->next;
            }
            ptrA = ptrA->next;
        }
        return nullptr;
    }
};

/* 
    1 -> 2 -> 3
    ^
    4 -> 3

 */