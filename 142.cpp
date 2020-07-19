/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
     Same as problem 141.
     T:O(n),S:O(n) with a hashmap
     ------------------
     Try to use 2 ptr.
     Definition:
         L1: head to entry
         L2: entry to the meet point (forward)
         C: circle length
     Steps Sum:
         slow: L1 + L2
         fast: L1 + L2 + nC
     Formula:
         2*slow=fast -> 2(L1+L2)=L1+L2+nC
                     -> L1+L2=nC
                     -> L1=nC-L2
                     -> L1=(n-1)C + (C-L2)
                                     ^
                                 distance meet point to entry(forward)
                     -> L1=(C-L2)
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {

        ListNode *header=new ListNode(0);
        header->next=head;
        ListNode *slow=header, *fast=header;
        while (fast&&fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) break;
        }
        if(slow!=fast||(fast==header&&slow==header)) return 0;
        slow=header;
        while(slow!=fast) {
            slow=slow->next;
            fast=fast->next;
        }
        delete header;
        return slow;
    }
};

/****************** Neat Code ******************/
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(!head||!head->next) return 0;
        ListNode *slow=head, *fast=head;
        while(fast&&fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) {
                while(slow!=head) {
                    slow=slow->next;
                    head=head->next;
                }
                return head;
            }
        }
        return 0;
    }
};
