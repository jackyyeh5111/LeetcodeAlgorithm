/*
    constraint: cannot modify the input lists. In other words, reversing the lists is not allowed.
    -----
    Use a container to record each node
    even stack(recursive) / vector could make it.
    T:O(n)/S:O(n) 2 pass iteration.
    -----
    make deep copy of input lists. Then we can reverse and do simply add op.
    T:O(n)/S:O(n) 3 pass iteration.
    -----
    Use an output list to record reversed result without carry handling.
	Reverse back and handle carry simultaneously.
	T:O(n)/S:O(n) 3 pass iteration
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *p1=l1,*p2=l2;
        while (p1&&p2) {
            p1=p1->next;
            p2=p2->next;
        }
        if (!p1) {swap(p1,p2); swap(l1,l2);}
        p2=l1;
        ListNode *header=new ListNode();
        while (p1) {
            ListNode *node=new ListNode(p2->val);
            node->next=header->next;
            header->next=node;
            p2=p2->next;
            p1=p1->next;
        }
        p1=l2;
        while (p1&&p2) {
            ListNode *node=new ListNode(p2->val+p1->val);
            node->next=header->next;
            header->next=node;
            p2=p2->next;
            p1=p1->next;
        }
        ListNode *prev=0, *head=header->next;
        int carry=0;
        while (head) {
            ListNode *next=head->next;
            int val=(head->val+carry)%10;
            carry=(head->val+carry)/10;
            head->val=val;
            head->next=prev;
            prev=head;
            head=next;
        }
        if (carry) {
            ListNode *newHead=new ListNode(1);
            newHead->next=prev;
            return newHead;
        }
        else return prev;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<ListNode*> s1,s2;
        ListNode *p1=l1,*p2=l2;
        while (p1) {s1.push(p1); p1=p1->next;}
        while (p2) {s2.push(p2); p2=p2->next;}
        ListNode *header=new ListNode();
        int carry=0;
        while (!s1.empty()&&!s2.empty()) {
            int sum=s1.top()->val+s2.top()->val+carry;
            int val=sum%10;
            carry=sum/10;
            ListNode *node=new ListNode(val);
            node->next=header->next;
            header->next=node;
            s1.pop(); s2.pop();
        }
        while (!s1.empty()) {
            int sum=s1.top()->val+carry;
            int val=sum%10;
            carry=sum/10;
            ListNode *node=new ListNode(val); s1.pop();
            node->next=header->next;
            header->next=node;
        }
        while (!s2.empty()) {
            int sum=s2.top()->val+carry;
            int val=sum%10;
            carry=sum/10;
            ListNode *node=new ListNode(val); s2.pop();
            node->next=header->next;
            header->next=node;
        }
        if (carry) {
            ListNode *node=new ListNode(1);
            node->next=header->next;
            header->next=node;
        }
        return header->next;
    }
};
