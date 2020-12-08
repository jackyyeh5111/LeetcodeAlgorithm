/***** Third Visit  *****/
/*
    Linked List: slow/fast ptr.
    say slow meets fast after k steps, and we have n nodes with acyclic a nodes and b cyclic nodes.
    Let k=a+d
    a+d=k
    2k=a+d+b*c
    k=b*c=a+d
    a=b*c-d=k-d,
    if we start on head and k node, they will meet on the node we are interested in.
    T:2 pass O(n)/S:O(1)
    -----
    Use a hashset to record visited ListNode.
    Iterate over each node and findout if duplicate or null.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) break;
        }
        if (!fast||!fast->next) return 0;
        slow=head;
        while (slow!=fast) {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};

/***** Second Visit *****/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    List slow/fast:
    n=a+b, we are going to find a. Say we found cycle after k steps with c cycles
    > a+d+b*c=2k, k=a+d
    > a+d+bc=2a+2d
    > a+d=bc=k
    > a=k-d=bc-d
    If we start from a+d and walk a again, we will meet in the start endian.
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) break;
        }
        if (!fast||!fast->next) return 0;
        slow=head;
        while(slow!=fast) {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};

/***** First Visit *****/
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
