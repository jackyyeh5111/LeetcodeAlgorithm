class Node {
public:
    int key;
    int val;
    Node *prev, *next;
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr){}
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> dict;
    Node *head, *tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (dict.find(key) == dict.end())
            return -1;
        remove(dict[key]);
        addTail(dict[key]);
        return dict[key]->val;
    }
    
    void put(int key, int value) {
        if (dict.find(key) == dict.end()) {
            dict[key] = new Node(key, value);
        }
        else { // update
            dict[key]->val = value;
            remove(dict[key]);
        }
        addTail(dict[key]);

        if (dict.size() > capacity) {
            dict.erase(head->next->key);
            remove(head->next);
        }
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addTail(Node* node) {
        node->prev = tail->prev;
        node->prev->next = node;
        node->next = tail;
        tail->prev = node;
    }
};

/**
    HEAD -> N1 -> N2 -> N3 -> TAIL
         <-    <-    <-    <-
    
    - Use a doubly linked list. And keep the head and the tail pointer
    - Maintain a map of type <key, Node>

    clarification:
    1. Get a Node in O(1) time.
    2. Put a Node in O(1) time.
    3. Remove a Node and put it in the last in O(1)
    4. Check the capacity of the linked list

    edge cases:
       DUMMY_head -> N1 -> DUMMY_tail
 */





