/***** Second Visit *****/
// T:O(n)/S:O(n)
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *header = new ListNode(), *tail = header;
        int c = 0;
        while (l1 && l2)
        {
            int num = l1->val + l2->val + c;
            tail->next = new ListNode(num % 10);
            c = num / 10;
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1)
            tail->next = l1;
        else
            tail->next = l2;
        while (c && tail->next)
        {
            tail = tail->next;
            int num = tail->val + c;
            tail->val = num % 10;
            c = num / 10;
        }
        if (c)
            tail->next = new ListNode(1);
        return header->next;
    }
};

// T:O(n)/S:O(1)
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int c = 0;
        ListNode *prev = 0, *head = l1;
        while (l1 && l2) {
            int num = l1->val + l2->val + c;
            l1->val = num % 10;
            c = num / 10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2) prev->next = l2;
        while (c && prev->next) {
            prev = prev->next;
            int num = prev->val + c;
            prev->val = num % 10;
            c = num / 10;
        }
        if (c) prev->next = new ListNode(1);
        return head;
    }
};

/***** First Visit *****/
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
