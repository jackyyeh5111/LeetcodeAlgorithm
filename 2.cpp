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
    notice carry in l2.
    we are quaranteed that two LL is non-empty.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *head=l1;
        int c=0; ListNode *prev=0;
        while(l1&&l2) {
            int sum=l1->val+l2->val+c;
            l1->val=sum%10; c=sum/10;
            prev=l1;
            l1=l1->next; l2=l2->next;
        }
        if (l2) prev->next=l2;
        while(prev&&prev->next) {
            int sum=prev->next->val+c;
            prev->next->val=sum%10;
            c=sum/10;
            prev=prev->next;
        }
        if (c) prev->next=new ListNode(1);
        return head;
    }

};
