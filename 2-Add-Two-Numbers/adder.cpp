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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1, *ptr2 = l2;
        int carry = 0;
        ListNode dummy;
        ListNode *ans = &dummy;
        while(l1 || l2) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry; // add latest carry 
            carry = sum / 10; // update carry
            ans->next = new ListNode(sum % 10);
            ans = ans->next;
        }

        // check final carry 
        if (carry)
            ans->next = new ListNode(1);
        
        return dummy.next;
    }
};

/* 
    clarification:
        1. int between 0 - 9
        2. no leading zero node

    case1:
        1 -> 2 (21)
        9 -> 8 (89)

        carry: 1

        21 + 89 = 110
        0 -> 1 -> 1

    case2:
        1 -> 2      ( 21)
        9 -> 8 -> 7 (789)

 */