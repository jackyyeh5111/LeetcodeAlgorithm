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
    int getDecimalValue(ListNode* head) {
        int val = 0;
        while(head){
            val= (val<<1) + head->val;
            head=head->next;
        }
        return val;
    }
};
