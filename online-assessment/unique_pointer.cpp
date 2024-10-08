#include <iostream>
#include <utility> // for std::move

template <typename T>
class UniquePointer {
private:
    T* ptr;  // Raw pointer to the object

public:
    // Constructor
    explicit UniquePointer(T* p = nullptr) : ptr(p) {}

    // Destructor
    ~UniquePointer() {
        delete ptr;  // Automatically deletes the object when the smart pointer is destroyed
    }

    // Delete copy constructor and assignment operator (No copying allowed)
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    // Move constructor (transfers ownership)
    UniquePointer(UniquePointer&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;  // Reset the other pointer to avoid double deletion
    }

    // Move assignment operator (transfers ownership)
    UniquePointer& operator=(UniquePointer&& other) noexcept {
        if (this != &other) {
            delete ptr;            // Clean up the current pointer
            ptr = other.ptr;       // Transfer ownership
            other.ptr = nullptr;   // Reset the other pointer
        }
        return *this;
    }

    // Dereference operator
    T& operator*() const {
        return *ptr;
    }

    // Arrow operator to access the object members
    T* operator->() const {
        return ptr;
    }

    // Get the raw pointer (not recommended to use directly)
    T* get() const {
        return ptr;
    }

    // Release ownership of the pointer (no deletion)
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // Reset the pointer to a new object
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
};

// Usage Example
int main() {
    UniquePointer<int> uptr(new int(42));
    std::cout << *uptr << std::endl;

    // UniquePointer<int> uptr2 = uptr;  // Compilation error due to deleted copy constructor
    UniquePointer<int> uptr2 = std::move(uptr);  // Ownership transferred
    std::cout << *uptr2 << std::endl;

    return 0;
}
