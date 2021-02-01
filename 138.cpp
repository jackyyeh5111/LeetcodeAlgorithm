/***** Third Visit *****/
/*
    Easy to tackle it with hashmap.
    Try to solve with S:O(1), excludes return space.
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur=head;
        while (cur) {
            Node *node=new Node(cur->val);
            node->next=cur->next;
            cur->next=node;
            cur=node->next;
        }
        cur=head;
        while(cur) {
            if (cur->random)
                cur->next->random=cur->random->next;
            cur=cur->next->next;
        }
        Node *newHead=0, *tail=0;
        cur=head;
        while(cur) {
            if (!newHead) {newHead=cur->next; tail=cur->next;}
            else {tail->next=cur->next; tail=tail->next;}
            cur->next=cur->next->next;
            cur=cur->next;
        }
        return newHead;
    }
};

/***** Second Visit *****/
class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        Node *tail=head;
        while (tail) {
            Node *copy=new Node(tail->val);
            Node *next=tail->next;
            copy->next=next;
            tail->next=copy;
            tail=copy->next;
        }
        tail=head;
        while (tail) {
            if (tail->random)
                tail->next->random=tail->random->next;
            tail=tail->next->next;
        }
        Node *header=new Node(0), *tailer=header;
        tail=head;
        while (tail) {
            Node *next=tail->next->next;
            tailer->next=tail->next;
            tail->next=next;
            tail=next;
            tailer=tailer->next;
        }
        return header->next;
    }
};

/***** First Visit *****/
/******* 1 pass without hash *******/
/*
    T:O(n), S:O(1)
    first pass: Create each copyNode right after original node.
    second pass: link each copyNode if randomNode exists.
    third pass: separate original nodes and copied nodes.
*/
class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        // constant space
        Node* tail=head;
        while(tail) {
            Node* copy=new Node(tail->val);
            Node* next=tail->next;
            tail->next=copy;
            copy->next=next;
            tail=tail->next->next;
        }
        tail=head;
        while (tail) {
            if(tail->random) tail->next->random=tail->random->next;
            tail=tail->next->next;
        }
        Node *newHead=0, *newTail=0;
        tail=head;
        while (tail) {
            if(!newHead) {newHead=tail->next; newTail=newHead;}
            else {
                newTail->next=tail->next;
                newTail=newTail->next;
            }
            tail->next=tail->next->next;
            tail=tail->next;
        }
        return newHead;
    }
};

/******* 1 pass with hash *******/
// T:O(n), S:O(n)
class Solution {
public:
    unordered_map<Node*, Node*> m;
    Node* copyRandomList(Node* head)
    {
        // 1 pass with a hashmap to store new node. same as problem. 133.
        if(!head) return 0;
        if(m.find(head)==m.end()){
            Node* newNode = new Node(head->val);
            m[head]=newNode;
            newNode->next=copyRandomList(head->next);
            newNode->random=copyRandomList(head->random);
        }
        return m[head];
    }
};
