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
class Solution2 {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = new ListNode(0), *even = new ListNode(0);
        ListNode* ptr_odd = odd, *ptr_even = even;
        int cnt = 1;
        while(head) {
            if (cnt % 2) {
                odd->next = head;
                odd = odd->next;
            }
            else {
                even->next = head;
                even = even->next;
            }
            
            head = head->next;
            cnt++;
        }
        even->next = nullptr; // important
        odd->next = ptr_even->next;
        return ptr_odd->next;
    }
};


/* 
    Wrong answer
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = new ListNode(0), *even = new ListNode(0);
        ListNode* ptr_odd = odd, *ptr_even = even;
        int cnt = 1;
        while(head) {
            if (cnt % 2) {
                odd->next = head;
                odd = odd->next;
            }
            else {
                even->next = head;
                even = even->next;
            }
            
            head = head->next;
            cnt++;
        }
        odd->next = ptr_even->next;
        return ptr_odd->next;
    }
};

/* 
    L1: 1 -> 3 -> ...
    L2: 2 -> 4
 */