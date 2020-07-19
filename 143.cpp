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
     T:O(n), S:O(n)
     2 pass solution with a hashmap, key, val are index and listnode
     respectively.
     ----------------
     3 pass:
         separate 2 lists;
         invert second one
         merge 2 lists
     T:O(n),S:O(1)
     ----------------
     Think about 1 pass solution, or use S:O(1) to solve it.
     use a dfs to get tail then construct the list, stop in the middle.
     1 pass, T:O(n) S:O(n) (recursive depth)

 */
class Solution {
public:
    ListNode *header, *tail;
    void reorderList(ListNode* head)
    {
        if(!head) return;
        header=head; tail=head;
        getTail(head);
    }

    void getTail(ListNode *node)
    {
        if (!node) return;
        getTail(node->next);
        if (!tail) return;
        if (tail==node||tail->next==node){
            if (tail->next==node) {tail->next=node;node->next=0;}
            else tail->next=0;
            tail=0;
            return;
        }

        ListNode *next=tail->next;
        tail->next=node;
        node->next=next;
        tail=next;
        return;

    }
};
