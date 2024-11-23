#include <iostream>
#include <list>
#include <vector>
#include <utility>  // For std::pair

template <typename KeyType, typename ValueType>
class HashMap {
private:
    // Bucket is a vector of linked lists (chaining method for collision handling)
    std::vector<std::list<std::pair<KeyType, ValueType>>> buckets;
    size_t bucket_count;  // Number of buckets

    // Hash function to get the index for a key
    size_t hashFunction(const KeyType &key) const {
        return std::hash<KeyType>{}(key) % bucket_count;
    }

public:
    // Constructor to initialize the number of buckets
    HashMap(size_t size = 10) : bucket_count(size) {
        buckets.resize(bucket_count);
    }

    // Insert a key-value pair into the hashmap
    void insert(const KeyType &key, const ValueType &value) {
        size_t index = hashFunction(key);
        // Check if the key already exists, and if so, update the value
        for (auto &pair : buckets[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        // If key does not exist, insert a new key-value pair
        buckets[index].emplace_back(key, value);
    }

    // Retrieve the value associated with a key
    bool get(const KeyType &key, ValueType &value) const {
        size_t index = hashFunction(key);
        // Look for the key in the linked list at the calculated index
        for (const auto &pair : buckets[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;  // Key not found
    }

    // Remove a key-value pair from the hashmap
    bool remove(const KeyType &key) {
        size_t index = hashFunction(key);
        auto &list = buckets[index];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->first == key) {
                list.erase(it);
                return true;
            }
        }
        return false;  // Key not found
    }

    // Print the hashmap (for debugging purposes)
    void print() const {
        for (size_t i = 0; i < bucket_count; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto &pair : buckets[i]) {
                std::cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    HashMap<std::string, int> map;

    // Insert key-value pairs
    map.insert("apple", 1);
    map.insert("banana", 2);
    map.insert("orange", 3);

    // Retrieve a value
    int value;
    if (map.get("apple", value)) {
        std::cout << "Value of 'apple': " << value << std::endl;
    } else {
        std::cout << "'apple' not found" << std::endl;
    }

    // Remove a key
    if (map.remove("banana")) {
        std::cout << "'banana' removed" << std::endl;
    }

    // Print the entire hashmap
    map.print();

    return 0;
}
