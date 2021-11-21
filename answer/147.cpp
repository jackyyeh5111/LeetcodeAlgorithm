/***** Third Visit *****/
/*
    Linked List:
    header node
    2 ptr solution
    -----
    methodology: insertion sort T:O(n^2)/S:O(1)
*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head)
    {
        ListNode *header=new ListNode();
        while (head) {
            ListNode *cur=header->next,*prev=header;
            while (cur&&cur->val<head->val) {
                prev=cur;
                cur=cur->next;
            }
            ListNode *next=head->next;
            prev->next=head;
            head->next=cur;
            head=next;
        }
        ListNode *ans=header->next;
        delete header;
        return ans;
    }
};

/***** Second Visit *****/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head)
    {
        ListNode *header=new ListNode();
        while (head) {
            ListNode *tail=header->next, *prev=header, *next=0;
            while (tail&&tail->val<=head->val) {
                prev=tail;
                tail=tail->next;
            }
            next=head->next;
            prev->next=head;
            head->next=tail;
            head=next;
        }
        return header->next;
    }
};

/***** First Visit *****/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head)
    {
        ListNode *header=new ListNode(0);
        ListNode *cur=head, *prev=header;
        while(cur) {
            ListNode *next=cur->next;
            while(prev->next&&prev->next->val<cur->val)
                prev=prev->next;
            cur->next=prev->next;
            prev->next=cur;
            prev=header; cur=next;
        }
        return header->next;
    }
};
