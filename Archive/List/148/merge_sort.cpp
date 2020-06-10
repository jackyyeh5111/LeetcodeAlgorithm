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
    ListNode* sortList(ListNode* head)
    {
        return sort(head);
    }

    ListNode* sort(ListNode* node)
    {
        if(!node || !node->next) return node;
        ListNode* slow=node; ListNode* fast=node;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rightHead=slow->next;
        slow->next=0;
        ListNode* left=sort(node);
        ListNode* right=sort(rightHead);

        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode* header=new ListNode(0);
        ListNode* tail=header;
        while(left && right) {
            if(left->val < right->val) {
                tail->next=left;
                left=left->next;
            }
            else { // left->val >= right->val
                tail->next=right;
                right=right->next;
            }
            tail=tail->next;
        }
        if (!left) tail->next=right;
        else tail->next=left;

        ListNode* tmp=header;
        header=header->next;
        delete(tmp);
        return header;
    }


};
