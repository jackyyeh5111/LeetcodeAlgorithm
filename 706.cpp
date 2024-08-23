class MyHashMap {
    struct Node {
        int key;
        int value;
        Node *next;
        Node(int key=-1, int value=-1) {
            this->key = key;
            this->value = value;
            this->next = nullptr;
        }
    };
public:
    int num_bucket = 1000;
    vector<Node*> hashmap;
    MyHashMap() {
        // hashmap.resize(num_bucket, new Node(-1, -1));
        hashmap.resize(num_bucket, nullptr);
        for (int i = 0; i < num_bucket; i++)
            hashmap[i] = new Node(-1, -1); // head node
    }
    
    void put(int key, int value) {
        int which = key % num_bucket; // 1
        Node* ptr = hashmap[which]; 
        while(ptr->next) {
            if (ptr->next->key == key) {
                ptr->next->value = value;
                return;
            }
            ptr = ptr->next;
        }

        ptr->next = new Node(key, value);
    }
    
    int get(int key) {
        int which = key % num_bucket;
        Node *ptr = hashmap[which];
        while(ptr) {
            if (ptr->key == key)
                return ptr->value;
            ptr = ptr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int which = key % num_bucket;
        Node *ptr = hashmap[which];
        while(ptr->next) {
            if (ptr->next->key == key) {
                cout << "key:" << key << '\n';
                cout << "node key: " << ptr->next->key << '\n';
                ptr->next = ptr->next->next;
                return;
            }
        }
    }
};
/* 
    key
    0: Dummy -> N -> N 
    1: Dummy -> N -> N -> N
    2: 
    3 
    4
 */
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */