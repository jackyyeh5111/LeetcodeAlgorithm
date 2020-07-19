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
    ListNode* sortList(ListNode* head)
    {
        /*
            merge sort can have O(nlogn) with constant space
            1234
               ^
            789
            ^
        */
        if(!head||!head->next) return head;
        ListNode *slow=head, *fast=head;
        while(fast->next&&fast->next->next){ // Handle 2 node linked list
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *list1=head, *list2=slow->next;
        slow->next=0;
        ListNode *left=sortList(list1);
        ListNode *right=sortList(list2);
        return merge(left,right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode *header=new ListNode(0);
        ListNode *tail=header;
        while(list1&&list2){
            if (list1->val<list2->val) {
                tail->next=list1;
                list1=list1->next;
            }
            else {
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
        if(!list1) tail->next=list2;
        if(!list2) tail->next=list1;
        tail=header; header=header->next;
        delete tail;
        return header;
    }
};
