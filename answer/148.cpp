/***** Second Visit *****/
/*
    Use a set(AVL) could easily sort with T:O(nlogn)/S:O(n)
    -----
    sort T:O(nlogn)/S:O(1) in-place sorting.
    LinkedList -> merge sort
    T(n)=2T(n/2)+O(n)=O(nlogn)
    recursive: S:O(logn)
    -----
    iterative: S:O(1)
    == step: 1
    4 2 1 3
    ^
    24 1 3
       ^
    24 13
         ^
    == step: 2
    24 13
    ^
    T(n)=logn * n

    1 5 6
      ^
    2 3 7
    ^

*/
class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        int n=0;
        ListNode *tail=head;
        while(tail) {n++; tail=tail->next;}
        for (int step=1; step<n; step*=2) {
            ListNode *l=head, *r=l; bool first=true; pair<ListNode*,ListNode*> prev;
            while (true){
                bool feasible=true;
                for (int i=0; i<step; ++i) {
                    if (!r) {feasible=false; break;}
                    r=r->next;
                }
                if(!feasible||!r) break;
                auto p=merge(l,r,step);
                if(first) {head=p.first; first=false; prev=p;}
                else {prev.second->next=p.first; prev=p;}
                l=p.second->next;
                r=l;
            }
            // cout<<"done"<<endl;
        }
        return head;
    }

    pair<ListNode*,ListNode*> merge(ListNode *l, ListNode *r, int size)
    {
        // cout<<l->val<<","<<r->val<<","<<size<<endl;
        ListNode *ll=l, *rr=r, *header=new ListNode(), *tail=header;
        int lsize=size,rsize=0;
        ListNode *next=rr;
        for (; rsize<size; ++rsize) {
            if(!next) break;
            next=next->next;
        }
        // cout<<"size"<<lsize<<","<<rsize<<endl;
        int total=lsize+rsize;
        for (int i=0; i<total; ++i) {
            if(lsize==0||rsize==0) break;
            if(ll->val>rr->val) {
                tail->next=rr;
                rr=rr->next;
                rsize--;
            }
            else {
                tail->next=ll;
                ll=ll->next;
                lsize--;
            }
            tail=tail->next;
            // cout<<"t"<<tail->val<<endl;
        }
        // cout<<"t"<<tail->val<<endl;
        if(lsize==0) tail->next=rr;
        else tail->next=ll;

        for(int i=0; i<lsize+rsize; ++i) tail=tail->next;
        tail->next=next;
        // cout<<"last"<<tail->val<<endl;
        ll=header->next;
        delete header;
        return make_pair(ll,tail);
    }
};

/***** First Visit *****/
class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        /*
            merge sort can have O(nlogn) with constant space
            1234
               ^
            789
            ^
        */
        if(!head||!head->next) return head;
        ListNode *slow=head, *fast=head;
        while(fast->next&&fast->next->next){ // Handle 2 node linked list
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *list1=head, *list2=slow->next;
        slow->next=0;
        ListNode *left=sortList(list1);
        ListNode *right=sortList(list2);
        return merge(left,right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode *header=new ListNode(0);
        ListNode *tail=header;
        while(list1&&list2){
            if (list1->val<list2->val) {
                tail->next=list1;
                list1=list1->next;
            }
            else {
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
        if(!list1) tail->next=list2;
        if(!list2) tail->next=list1;
        tail=header; header=header->next;
        delete tail;
        return header;
    }
};
