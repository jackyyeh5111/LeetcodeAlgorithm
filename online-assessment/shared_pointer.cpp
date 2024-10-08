#include <iostream>

template <typename T>
class SharedPointer {
private:
    T* ptr;  // raw pointer to the object
    int* ref_count;  // reference count

public:
    // Constructor
    explicit SharedPointer(T* p = nullptr) : ptr(p), ref_count(new int(1)) {
        if (ptr == nullptr) {
            *ref_count = 0;
        }
    }

    // Copy constructor
    SharedPointer(const SharedPointer<T>& sp) {
        ptr = sp.ptr;
        ref_count = sp.ref_count;
        (*ref_count)++;  // Increase the reference count
    }

    // Assignment operator
    SharedPointer<T>& operator=(const SharedPointer<T>& sp) {
        if (this != &sp) {
            // Decrease the old reference count
            // If no one is referencing the old object, delete it
            if (--(*ref_count) == 0) {
                delete ptr;
                delete ref_count;
            }

            // Copy new data
            ptr = sp.ptr;
            ref_count = sp.ref_count;
            (*ref_count)++;  // Increase the new reference count
        }
        return *this;
    }

    // Destructor
    ~SharedPointer() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }

    // Dereference operator
    T& operator*() const {
        return *ptr;
    }

    // Arrow operator
    T* operator->() const {
        return ptr;
    }

    // Get the raw pointer
    T* get() const {
        return ptr;
    }

    // Get reference count
    int use_count() const {
        return *ref_count;
    }

    // Reset the shared pointer
    void reset(T* p = nullptr) {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
        ptr = p;
        ref_count = new int(1);
    }
};

// Example usage
int main() {
    SharedPointer<int> sp1(new int(10));  // Creating shared pointer
    std::cout << "sp1 count: " << sp1.use_count() << std::endl;  // Output: 1
    std::cout << "sp1 value: " << *sp1 << std::endl;  // Output: 10

    {
        SharedPointer<int> sp2 = sp1;  // Copy constructor, both point to the same object
        std::cout << "sp1 count: " << sp1.use_count() << std::endl;  // Output: 2
        std::cout << "sp2 count: " << sp2.use_count() << std::endl;  // Output: 2
    }

    std::cout << "sp1 count after sp2 goes out of scope: " << sp1.use_count() << std::endl;  // Output: 1

    sp1.reset();  // Reset the pointer, ref_count becomes 0, memory is freed
    std::cout << "sp1 count after reset: " << sp1.use_count() << std::endl;  // Output: 1 (but points to nullptr)

    return 0;
}
