/***** Third Visit *****/
class Solution {
public:
    void deleteNode(ListNode* node)
    {
        *node=*(node->next);
    }
};

class Solution {
public:
    void deleteNode(ListNode* node)
    {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};

/***** Second Visit *****/
/*
    Given only the access of the node which means we can't access its
    parent. Thus iterate to the end and modify the value.
    T:O(n)/S:O(1)
    ----
    Modify its value to the next ptr's val, and skip the next ptr.
    T:O(1)/S:O(1)
*/
class Solution {
public:
    void deleteNode(ListNode* node)
    {
        ListNode *tail=node, *prev=node;
        while (tail->next) { //The given node exists
            tail->val=tail->next->val;
            prev=tail;
            tail=tail->next;
        }
        prev->next=0;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node)
    {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node)
    {
        *node=*(node->next);
    }
};

/***** First Visit *****/
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* tmp = node->next;
        node->next = tmp->next;
        node->val = tmp->val;
        delete tmp;
    }
};
