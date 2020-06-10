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
