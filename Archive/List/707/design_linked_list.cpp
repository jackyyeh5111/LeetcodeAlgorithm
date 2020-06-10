class Node {
public:
    int val=0;
    Node* next=0;
    Node(int val){this->val=val;}
}

class MyLinkedList {
public:
    Node* head=0;

    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new Node(0);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node* q=head;

        for(int i=-1;i<index;++i){
            q=q->next;
            if(!q) return -1;
        }
        return q->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head->next;
        head->next = node;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* q = head;
        while(q->next) q=q->next;
        Node* node = new Node(val);
        q->next=node;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node* q=head;
        Node* r=head;

        for (int i=-1;i<index;++i){
            if (!q) return;
            r=q; q=q->next; 
        }
        Node* node = new Node(val);
        node->next=q;
        r->next = node;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node* q=head;
        Node* r=head;

        for (int i=-1;i<index;++i){
            if (!q) return;
            r=q; q=q->next;
        }
        if (!q) return;
        r->next = q->next;
        delete(q);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
