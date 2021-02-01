/***** Third Visit *****/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode *header=new ListNode();
        ListNode *tail=header;
        while (head) {
            if (!head->next||(head->next->val!=head->val)){
                tail->next=head;
                tail=tail->next;
            }
            else {
                while (head->next&&head->next->val==head->val)
                    head=head->next;
            }
            head=head->next;
        }
        tail->next=0;
        return header->next;
    }
};

/***** Second Visit *****/
/*
    LL:
    1. header node (V)
    2. slow/fast ptr
    -----
    T:O(n)/S:O(1)
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode *header = new ListNode();
        header->next=head;
        ListNode *p=header, *q=0;
        while (p) {
            q=p->next;
            while (q&&q->next&&q->next->val==q->val)  {
                while (q&&q->next&&q->next->val==q->val) q=q->next;
                q=q->next;
            }
            p->next=q;
            p=p->next;
        }
        return header->next;
    }
};

 /***** First Visit *****/
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
