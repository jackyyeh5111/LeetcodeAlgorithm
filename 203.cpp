/***** Second Visit *****/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode *header = new ListNode(), *tail=header;
        while (head) {
            if (head->val==val) {
                ListNode *next=head->next;
                delete head;
                head=next;
            }
            else {
                tail->next=head;
                head=head->next;
                tail=tail->next;
            }
        }
        tail->next=0;
        return header->next;
    }
};

/***** First Visit *****/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode *header=new ListNode(0);
        header->next=head;
        ListNode *prev=header, *tail=header->next;
        while(tail) {
            if (tail->val==val) {
                prev->next=tail->next;
                delete tail;
                tail=prev->next;
            }
            else {prev=tail; tail=tail->next;}
        }
        return header->next;
    }
};
