/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

/***** Use cyclic double linked list to avoid duplicate vists *****/
class Solution {
public:
    Node* flatten(Node* head)
    {
        Node* ret=help(head);
        if (ret) {
            ret->prev->next=0;
            ret->prev=0;
        }
        return ret;
    }

    Node* help(Node* head)
    {
        if (!head) return 0;
        Node *tail=head; Node* prev=0;
        while(tail) {
            // cout<<tail->val<<endl;
            if (tail->child) {
                Node *child=help(tail->child);
                tail->child=0;
                Node *next=tail->next;
                tail->next=child;
                Node *child_tail=child->prev;
                child->prev=tail;
                child_tail->next=next;
                if(next) next->prev=child_tail;
                prev=child_tail;
                tail=next;
            }
            else {prev=tail; tail=tail->next;}
        }
        // cout<<prev->val<<endl;
        prev->next=head;
        head->prev=prev;
        return head;
    }
};


/************** neat code but duplicate visits **************/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* tail = head;
        while (tail) {
            if (tail->child) {
                Node* child = flatten(tail->child);
                tail->child = 0;
                Node* next = tail->next;
                tail->next = child;
                child->prev = tail;
                while(tail->next) tail = tail->next;
                tail->next = next;
                if (next) next->prev = tail;
            }
            tail=tail->next;
        }
        return head;
    }
};
