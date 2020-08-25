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
/*
    Use a hashmap to record val/index with 2 ptr for mid finding.
    T:O(n) one pass / S:O(n)
    -------------
    Inverse the left part and use 2 ptr to find mid.
    Then start comparison from start/mid to end.
    T:O(n), S:O(1), but we may modify the link list order
    To recover it, reverse left part again -> 2 pass.

    12321 fast!=0
      ^ ^
    1221 fast==0
      ^ ^
*/
class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        if (!head) return true;
        ListNode *slow=head, *fast=head, *prev=0;
        while (fast&&fast->next) {
            fast=fast->next->next;
            ListNode *next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
        // cout<<prev->val<<","<<slow->val<<endl;
        ListNode *l=prev, *r=fast?slow->next:slow;
        while(r) {
            // cout<<l->val<<","<<r->val<<endl;
            if (r->val!=l->val) return false;
            r=r->next; l=l->next;
        }
        return true;
    }
};
