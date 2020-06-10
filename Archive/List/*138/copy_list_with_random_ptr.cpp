/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// Time: O(n), Space: O(n)
class Solution {
public:
    map<Node*,Node*> old2new;
    Node* copyRandomList(Node* head) {
        if (!head) return 0;
        Node* node = new Node(head->val);
        old2new[head] = node;
        node->next = copyRandomList(head->next);
        if(head->random)
            node->random = old2new[head->random];
        return node;
    }
};


// Time: O(n), Space: O(1)
// Change insert each copied node right next to the origin node, then we can
//   have mapping of mirroed list's random ptr.
// First pass: insert each copied node.
// Second pass: Assign random ptr node.
// Third pass: reorder mirroed node.

RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *newHead, *l1, *l2;
    if (head == NULL) return NULL;
    for (l1 = head; l1 != NULL; l1 = l1->next->next) {
        l2 = new RandomListNode(l1->label);
        l2->next = l1->next;
        l1->next = l2;
    }

    newHead = head->next;
    for (l1 = head; l1 != NULL; l1 = l1->next->next) {
        if (l1->random != NULL) l1->next->random = l1->random->next;
    }

    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = l1->next;
        l1->next = l2->next;
        if (l2->next != NULL) l2->next = l2->next->next;
    }

    return newHead;
}
