/***** Third Visit *****/
/*
    invert the first left part, then do comparison
    T:O(n) 1 pass / S:O(1)
*/
class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode *prev=0, *slow=head, *fast=head;
        while (fast&&fast->next) {
            fast=fast->next->next;
            ListNode *next=slow->next;
            slow->next=prev;
            prev=slow; slow=next;
        }
        if (fast) slow=slow->next;
        while (slow&&prev) {
            if (slow->val!=prev->val) return false;
            slow=slow->next;
            prev=prev->next;
        }
        return true;
    }
};

/***** Second Visit *****/
/*
    2 pass O(n)
    Inverse the LL from header node until mid one.
    T:O(n)/S:O(1) 2 pass
    [1,2,2,1]
    [1,2,3,4,5]
         ^   ^
       ^ ^
*/
class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode *cur=head, *prev=0, *slow=head, *fast=head;
        while (fast&&fast->next) {
            ListNode *slow_next=slow->next;
            ListNode *fast_next=fast->next->next;

            ListNode *next=cur->next;
            cur->next=prev;
            prev=cur; cur=next;

            slow=slow_next;
            fast=fast_next;
        }
        // compare slow with prev;
        if (fast) slow=slow->next;
        while(slow&&prev) {
            if (slow->val!=prev->val) return false;
            slow=slow->next;
            prev=prev->next;
        }
        return !slow&&!prev;
    }
};

/***** First Visit *****/
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
