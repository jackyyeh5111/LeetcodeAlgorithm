/******* Fifth Visit *******/
/*
    T:O(n^2) by insert n-1, n-2, ... etc.
    -----
    12 43
    12345
    123 54
    123
     ^
      ^
*/
class Solution {
public:
    void reorderList(ListNode* head)
    {
        ListNode *slow=head,*fast=head;
        while (fast->next&&fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=0;
        ListNode *prev=0;
        while (fast) {
            ListNode *next=fast->next;
            fast->next=prev;
            prev=fast; fast=next;
        }
        ListNode *l1=head,*l2=prev;
        ListNode *header=new ListNode(),*tail=header;
        while (l1&&l2) {
            ListNode *next1=l1->next,*next2=l2->next;
            tail->next=l1; l1->next=l2;
            tail=l2;
            l1=next1; l2=next2;
        }
        tail->next=l1;
    }
};

/******* Fourth Visit *******/
class Solution {
public:
    void reorderList(ListNode* head)
    {
        ListNode *slow=head,*fast=head,*prev=0;
        while(fast&&fast->next) {
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        if (prev) prev->next=0;
        prev=0;
        while (slow) {
            ListNode *next=slow->next;
            slow->next=prev;
            prev=slow; slow=next;
        }
        ListNode *header=new ListNode(),*tail=header;
        while (prev&&head&&prev!=head) {
            ListNode *next=head->next;
            tail->next=head;
            tail->next->next=prev;
            head=next;
            prev=prev->next;
            tail=tail->next->next;
        }
    }
};

/******* Third Visit *******/
/*
    Use a vector with indexing
    T:2 pass O(n)/S:O(n)
    -----
    Reverse the rest
    T(N)=T(n-1)+...+T(1)+O(n)
        =O(n^2)
    S:O(1)
    -----
    3 pass solution with T:O(n)
    1st Find the mid
    2st inverse from mid to end
    3st merge
    T:O(n)/S:O(1)
*/
class Solution {
public:
    void reorderList(ListNode* head)
    {
        ListNode *slow=head,*fast=head, *p=0;
        while(fast&&fast->next) {
            p=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if (p) p->next=0;
        ListNode *prev=0;
        fast=slow;
        while(fast) {
            ListNode *next=fast->next;
            fast->next=prev;
            prev=fast;
            fast=next;
        }
        ListNode *header=new ListNode(), *tail=header;
        while(prev&&head&&prev!=head) {
            ListNode *next=head->next;
            tail->next=head;
            tail->next->next=prev;
            head=next;
            prev=prev->next;
            tail=tail->next->next;
        }
    }
};

/******* Second Visit *******/
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
    void reorderList(ListNode* head)
    {
        if (!head) return;
        stack<ListNode*> s;
        ListNode *tail=head;
        while (tail) { s.push(tail); tail=tail->next; }
        tail=head;
        while (tail->next!=s.top()&&tail!=s.top()) {
            ListNode* next=tail->next;
            tail->next=s.top(); s.pop();
            tail->next->next=next;
            tail=next;
        }
        if (tail!=s.top()) {
            tail->next=s.top(); s.pop();
            tail=tail->next;
        }
        tail->next=0;
        return;
    }
};

class Solution {
public:
    void reorderList(ListNode* head)
    {
        ListNode *slow=head,*fast=head;
        int n=0;
        while(fast&&fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            n++;
        }
        ListNode *prev=0, *cur=slow;
        while(cur){
            ListNode *next=cur->next;
            cur->next=prev;
            prev=cur; cur=next;
        }
        cur=head;
        for (int i=0; i<n; ++i) {
            ListNode *next=cur->next;
            cur->next=prev;
            prev=prev->next;
            if (cur->next->next) cur->next->next=next;
            cur=next;
        }
    }
};

/******* First Visit *******/
 /*
    backtracking from tail ptr and forward tracking from head ptr.
    it could be implemented by iterative/recursive.
    T:O(n)/S:O(n)
    ----------------
    iterative:
    stack -> 1 2 3 4
                 ^
    stack -> 1 2 3 4 5
                 ^
    stop criteria pt->next==p2 || p1==p2
    ----------------
    Remember to inverse second part then merge
    T:O(n) 3 pass / S:O(1)
*/
class Solution {
public:
    ListNode *tail;
    void reorderList(ListNode* head)
    {
        if(!head) return;
        tail=head;
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
