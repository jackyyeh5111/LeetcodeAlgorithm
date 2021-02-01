/***** Fifth Visit *****/
/*
    1 pass to find length
    2 pass with fast/slow ptr to reach new head ptr, i.e. slow, with prev(slow), fast.
        fast->next=head; prev(slow)->next=0; return slow;
    T:O(n)/S:O(1)
*/

/***** Fourth Visit *****/
/*
    1 2 3 4 5
    5 4 3 2 1 inverse all path
    4 5 1 2 3 separately inverse first k and the rest.
    T:O(n) 3 pass, actually we can combine n calc while all paths inverse.
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head) return 0;
        int n=0;
        ListNode *cur=head;
        while (cur) {cur=cur->next; n++;}
        k%=n;
        if (k==0) return head;
        auto p1=inverse(head,n);
        auto p2=inverse(p1[0],k);
        auto p3=inverse(p2[2],n-k);
        p2[1]->next=p3[0];
        return p2[0];
    }

    // <head,tail,next>
    vector<ListNode*> inverse(ListNode *head, int k)
    {
        if (!head) return {0,0,0};
        ListNode *prev=0, *cur=head;
        for (int i=0; i<k; ++i) {
            ListNode *next=cur->next;
            cur->next=prev;
            prev=cur; cur=next;
        }
        return {prev,head,cur};
    }
};

/***** Third Visit *****/
/*
    List:
    1. header node
    2. slow/fast ptr (V)
    Note that k may be larger than the length of linked list.
    Methodology:
    First pass to seek length n.
    Second pass to rotate k%n nodes.
    T: 2 pass O(n)/S:O(1)
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head) return head;
        ListNode *tail=head;
        int n=0;
        while(tail&&tail->next) {tail=tail->next; n++;}
        tail->next=head; n++;
        k=(k+1)%n;
        ListNode *slow=head;
        for(int i=0;i<n-k; ++i) slow=slow->next;
        ListNode *newhead=slow->next;
        slow->next=0;
        return newhead;
    }
};

/***** Second Visit *****/
/*
    1. Find the length of list
    2. use fast/slow solution to get the right position.
    3. inverse the two ptr.
    T:2 pass O(n)/S:O(1) in-place
    -----
    Directly iterate k steps to find target ListNode with newTail/newHead;
    move to the current end.
    end->next=head, newTail->next=0, return newHead
    T:O(1+k/n)/S:O(1)
    -----
    Use a hashmap, k: idx, v: ListNode*
    First pass, fill in the hashmap, and find length.
    Make cyclic.
    Then count the index from k, and we can find prev as well.
    prev->next=0;  return map[k];
    T:O(n)/S:O(n)
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head||!head->next||k==0) return head;
        ListNode *tail=head;
        while(k>0) {
            if (!tail) tail=head->next;
            else tail=tail->next;
            --k;
        }
        if(!tail) return head;
        ListNode* newHead=head;
        while(tail&&tail->next) {newHead=newHead->next; tail=tail->next;}
        tail=newHead; newHead=newHead->next;
        tail->next=0;
        tail=newHead;
        while(tail&&tail->next) tail=tail->next;
        tail->next=head;
        return newHead;
    }
};

/***** First Visit *****/
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
