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
