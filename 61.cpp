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
 /****************** 1 Pass with map************************/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        //T:O(n), S:O(n)
        // Use a hashtable to record each node in first iteration and have length
        // Link as cyclic
        // make length-k%length -1 points to null and return length-k%length
        // Notice if length-k%length==0, then -1 would be treat as length-1
        if (!head||k==0) return head;
        unordered_map<int, ListNode*> table;
        int length=0;
        while (head) { table[length++]=head; head=head->next; }
        table[length-1]->next = table[0]; // make cyclic
        int target = (length-k%length)%length;
        int prev = target==0? length-1:target-1;
        table[prev]->next=0;
        return table[target];

    }
};

/****************** 2 Pass ************************/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        // Use a hashtable to record each node in first iteration and have length
        // Link as cyclic
        // make length-k%length -1 points to null and return length-k%length
        // Notice if length-k%length==0, then -1 would be treat as length-1
        if (!head||k==0||!head->next) return head;
        int length=1; ListNode* tail=head;
        while(tail->next){
            length++; tail=tail->next;
        }
        tail->next=head;
        k=k%length;
        for (int i=0; i<length-k; ++i) {
            tail=head;
            head=head->next;
        }
        tail->next=0;
        return head;

    }
};
