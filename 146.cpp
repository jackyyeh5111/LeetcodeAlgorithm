/***** Second Visit *****/
/*
    data stucture:
        Linked List: to keep LRU order
        hashmap: k: key, v: the prev ListNode, i.e. ahead of target ListNode.
        get:
            move the node to the head.
        put: insert in the beginning.
        T:O(1)/S:O(n)
    FAIL, we cannot tackle this problem with single hashmap.
    Thus, devise 2 hashmap with double linked list could heelp.
    T:O(n)/S:O(1)

*/
class LRUCache {
private:
    struct ListNode {
        int val=0;
        ListNode *right=0,*left=0;
        ListNode(){this->val=0; right=0; left=0;};
        ListNode(int val){this->val=val; right=0; left=0;};
    };
    ListNode *header=0, *tail=0;
    unordered_map<int,ListNode*> m;
    unordered_map<ListNode*,int> invert_m;
    int size=0;
public:
    LRUCache(int capacity) {
        size=capacity;
        header=new ListNode();
        tail=header;
    }

    int get(int key)
    {
        if (m.count(key)==0) return -1;
        // cout<<"get"<<key<<endl;
        ListNode *target=m[key];
        if (target==tail&&m.size()!=1) tail=tail->left;
        if (target->right) target->right->left=target->left;
        target->left->right=target->right;
        target->right=header->right;
        if (header->right) header->right->left=target;
        target->left=header;
        header->right=target;;
        return m[key]->val;
    }

    void put(int key, int value)
    {
        if (get(key)!=-1) header->right->val=value;
        else {
            ListNode *node=new ListNode(value);
            if (m.size()==0) tail=node;
            node->right=header->right;
            if (node->right) node->right->left=node;
            node->left=header;
            header->right=node;
            m[key]=node;
            invert_m[node]=key;
        }
        if (m.size()>size) {
            m.erase(invert_m[tail]);
            invert_m.erase(tail);
            tail=tail->left;
            tail->right=0;
            delete tail->right;
        }
    }
};

/***** First Visit *****/
class LRUCache {
private:
    unordered_map<int,int> cache;
    unordered_map<int,list<int>::iterator> pos;
    list<int> recent;
    int capacity=0;

    void use(int key)
    {
        if(pos.find(key)!=pos.end()) recent.erase(pos[key]);
        else if (recent.size()>=capacity) {
            int old=recent.back();
            recent.pop_back();
            pos.erase(old);
            cache.erase(old);
        }
        recent.push_front(key);
        pos[key]=recent.begin();
    }

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }

    int get(int key) {
        if (cache.find(key)==cache.end()) return -1;
        use(key);
        return cache[key];
    }

    void put(int key, int value) {
        use(key);
        cache[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
