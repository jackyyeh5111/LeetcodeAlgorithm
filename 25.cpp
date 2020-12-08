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

/***** Second Visit *****/
/*
    same as problem 24.
    use 2 ptr to check should reverse or not.
    DIRTY code.
    -----
    uuse recursive approach to get neat code
    T:O(n) 2 pass/S:O(n/k)
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode *slow=head, *fast=head;
        for (int i=0; i<k; ++i) {
            if (!fast) return head;
            fast=fast->next;
        }
        ListNode *header=reverse(head,fast);
        head->next=reverseKGroup(fast,k);
        return header;
    }

    ListNode* reverse(ListNode *l, ListNode *r)
    {
        ListNode *prev=0;
        while(l!=r) {
            ListNode *tmp=l->next;
            l->next=prev;
            prev=l; l=tmp;
        }
        return prev;
    }
};

/***** First Visit *****/
class Solution {
public:
    // T: O(2n) due to two pass iteration, S:O(1)
    // User multiple pointers to implement iterative checking reverse or not.
    // We can use recursive solution for Elegant way, but S:O(n/k) instead.
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head || k == 1) return head;
        ListNode* header = new ListNode(0);
        header->next = head;
        do {
            ListNode* tail = header;
            bool should_reverse=true;
            for (int i=0; i<k; ++i){
                if (tail->next)
                    tail = tail->next;
                else {
                    should_reverse=false;
                    break;
                }
            }
            if(!should_reverse) break;
            ListNode* tmp = tail->next;
            invertList(header->next, tail);
            if(head==header->next) head=tail; //first reverse header asignment
            header->next->next = tmp;
            tmp = header->next;
            header->next = tail;
            header = tmp;
        } while(true);

        return head;
    }

    void invertList(ListNode* start, ListNode* end)
    {
        ListNode* q=0;
        ListNode* r=0;
        while(q!=end) {
            r = start->next;
            start->next = q;
            q=start; start=r;
        }
    }
};


/***************** recursive for elegant ****************/

class Solution
{
public:
    // T: O(2n) due to two pass iteration, S:O(n/k) due to recursive
    ListNode* reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last;

        while ( first != last )
        {
            auto tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        auto node=head;
        for (int i=0; i < k; ++i)
        {
            if ( ! node  )
                return head; // nothing to do list too sort
            node = node->next;
        }

        auto new_head = reverse( head, node);
        head->next = reverseKGroup( node, k);
        return new_head;
    }
};
