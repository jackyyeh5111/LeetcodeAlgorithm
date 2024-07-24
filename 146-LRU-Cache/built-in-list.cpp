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