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
    ListNode* deleteDuplicates(ListNode* head)
    {
        /*
        Use 2 pointer, say tail and distinct,
        we use tail to visit the whole linked list, and distinct indicates the tail of distinct value.
        T:O(n)
        ------ mis understanding questions, above code will return distinct array includes duplicate number. ----------
        we use a pointer cur to represent each new number, and check if duplicated via while lopp in while loop.
        */
        ListNode *header=new ListNode(0);
        ListNode *tail=header, *cur=head;
        while(cur){
            int tmp=cur->val; bool distinct=true;
            while(cur->next&&cur->next->val==tmp){
                cur=cur->next;
                distinct=false;
            }
            if (distinct) {tail->next=cur; tail=tail->next;}
            cur=cur->next;
        }
        tail->next=0;
        return header->next;
    }
};
