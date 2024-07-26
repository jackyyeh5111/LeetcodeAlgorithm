/* 
    Add touch function

    get:
        1. key not exists: return -1
        2. key exists: return val. Then put the node to the tail of list.
    put:
        1. key not exists: 
            a. put the node to the tail of list. update hashmap
            b. If capacity exceeds, remove the front node in the list, and update hash map

    1 -> 3 -> 2

    hashmap: // key -> node_ptr
        1 -> ptr_to_node_1
        2 -> ptr_to_node_2
        3 -> ptr_to_node_3
 */

class LRUCache {
public:
    int capacity_;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hashmap;
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (hashmap.count(key) == 0)
            return -1;
        touch(key);
        return hashmap[key]->second;
    }
    
    void put(int key, int value) {
        if (hashmap.count(key) == 0) {
            cache.push_back({key, value});
            hashmap[key] = prev(cache.end());
            if (cache.size() > capacity_) {
                hashmap.erase(cache.begin()->first);
                cache.pop_front();
            }
        }
        else {
            touch(key);
            hashmap[key]->second = value;
        }
    }
    void touch(int key) {    
        auto it = hashmap[key];
        cache.push_back(*it);
        cache.erase(it);
        hashmap[key] = prev(cache.end());
    }
};

/* More elegant 
    doubly linked list!
*/
class LRUCache {
public:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> dict;
    list<pair<int, int>> lru_cache;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (dict.count(key) == 0)
            return -1;
        auto iter = dict[key];
        lru_cache.splice(lru_cache.end(), lru_cache, dict[key]);
        return dict[key]->second;
    }
    
    void put(int key, int value) {
        if (dict.count(key) == 0) {
            lru_cache.push_back({key, value});
            dict[key] = prev(lru_cache.end());
        }
        else {
            lru_cache.splice(lru_cache.end(), lru_cache, dict[key]);
            dict[key]->second = value;
        }
        if (lru_cache.size() > capacity) {
            dict.erase(lru_cache.begin()->first);
            lru_cache.pop_front();
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
public:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> dict;
    list<pair<int, int>> lru_cache;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (dict.count(key) == 0)
            return -1;
        auto iter = dict[key];
        lru_cache.splice(lru_cache.end(), lru_cache, dict[key]);
        dict[key] = prev(lru_cache.end()); // redundant
        return dict[key]->second;
    }
    
    void put(int key, int value) {
        if (dict.count(key) == 0) {
            lru_cache.push_back({key, value});
            dict[key] = prev(lru_cache.end());
        }
        else {
            lru_cache.splice(lru_cache.end(), lru_cache, dict[key]);
            dict[key] = prev(lru_cache.end()); // redundant
            dict[key]->second = value;
        }
        if (lru_cache.size() > capacity) {
            dict.erase(lru_cache.begin()->first);
            lru_cache.pop_front();
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */