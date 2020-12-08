/***** Second Visit *****/
/*
    Use a hashmap to record each visited node from a/b endian.
    T:O(n)/S:O(n)
    -----
    Use 2 ptr solution
    T:2 pass O(n)/S:O(1)
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a=headA,*b=headB;
        while (a&&b) {
            a=a->next;
            b=b->next;
        }
        if (!b) {swap(headA,headB); swap(a,b);}
        while (b) {headB=headB->next; b=b->next;}
        while (headA&&headB) {
            if (headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return 0;
    }
};

/***** First Visit *****/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        /*
            Use a hashtable to record all nodes of headA, and check on headB
            T:O(n), S:O(n)
            ---------------------
            A:a+c
            B:b+c
            b+c-a-c=b-a right here we know the difference of a and b.
            move the b ptr forward b-a, than start both a/b, then we can find
            intersection if a==b
        */
        ListNode *a=headA, *b=headB;
        while(a&&b) {
            a=a->next;
            b=b->next;
        }
        if (!a) {swap(a,b); swap(headA,headB);} // assume always b is shorter.
        ListNode *c=headA;
        while(a){
            a=a->next;
            c=c->next;
        }
        b=headB;
        while(c&&b){
            if (c==b) return b;
            c=c->next;
            b=b->next;
        }
        return 0;
    }
};

/******************** Neat Code ********************/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(!headA||!headB) return 0;
        ListNode *a=headA, *b=headB;
        while(a&&b&&a!=b) {
            a=a->next;
            b=b->next;
            if (a==b) return a;
            if(!a) a=headB;
            if(!b) b=headA;
        }
        return a;
    }
};
