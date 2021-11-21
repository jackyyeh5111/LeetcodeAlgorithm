/***** Fifth Visit *****/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *head=new ListNode(),*tail=head;
        while (l1&&l2) {
            if (l1->val<=l2->val) {tail->next=l1; l1=l1->next;}
            else {tail->next=l2; l2=l2->next;}
            tail=tail->next;
        }
        if (l1) tail->next=l1;
        else tail->next=l2;
        return head->next;
    }
};

/***** Fourth Visit *****/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *header=new ListNode(), *tail=header;
        while (l1&&l2) {
            if (l1->val<l2->val) {tail->next=l1; l1=l1->next; }
            else {tail->next=l2; l2=l2->next;}
            tail=tail->next;
        }
        if (l1) tail->next=l1;
        if (l2) tail->next=l2;
        tail=header; header=header->next;
        delete tail;
        return header;
    }
};

/***** Third Visit *****/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *header = new ListNode();
        ListNode *tail=header;
        while (l1&&l2) {
            if (l1->val<l2->val) {
                tail->next=l1;
                l1=l1->next;
            }
            else {
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        if (l1) tail->next=l1;
        else tail->next=l2;
        return header->next;
    }
};

/***** Second Visit *****/
/*
    We are asked to merge into a NEW sorted list
    T:O(m+n)/S:O(m+n)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *header=new ListNode(0);
        ListNode *p1=l1, *p2=l2, *cur=header;
        while(p1&&p2) {
            if(p1->val<=p2->val) {
                cur->next=new ListNode(p1->val);
                p1=p1->next;
            }
            else {
                cur->next=new ListNode(p2->val);
                p2=p2->next;
            }
            cur=cur->next;
        }
        if (p1) {
            while(p1) {
                cur->next=new ListNode(p1->val);
                p1=p1->next;
                cur=cur->next;
            }
        }
        else if (p2) {
            while(p2) {
                cur->next=new ListNode(p2->val);
                p2=p2->next;
                cur=cur->next;
            }
        }
        return header->next;
    }
};

/***** First Visit *****/
class Solution {
public:
    // T:O(n), S:O(1)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        else if (!l2) return l1;

        ListNode* header = new ListNode(0);
        ListNode* head = header;
        while(l1&&l2) {
            if (l1->val<l2->val) {
                head->next = l1;
                l1=l1->next;
            }
            else {
                head->next = l2;
                l2=l2->next;
            }
            head=head->next;
        }

        if(!l1) head->next=l2;
        if(!l2) head->next=l1;
        head = header->next;
        delete header;
        return head;
    }
};
