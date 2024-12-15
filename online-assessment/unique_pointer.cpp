#include <iostream>
#include <utility> // for std::move

template <typename T>
class UniquePointer {
private:
    T* ptr;  // Raw pointer to the object

public:
    // Constructor
    // explicit keyword avoids unintended type conversion.
    /* 
        ex: 
            int* int_ptr = new int(42);
            // If some exception happens in the middle, memory leak happens!!
            UniquePointer<Data> uptr = int_ptr;  // Implicit conversion from int* to UniquePointer<int>

     */
    explicit UniquePointer(T* p = nullptr) : ptr(p) {}

    /* 
        error:
            cannot initialize a member subobject of type 'int *' with an lvalue of
      type 'const int *'
            - ptr: int *
            -   p: const int * 

     */
    // explicit UniquePointer(const T* p = nullptr) : ptr(p) {}

    // Destructor
    ~UniquePointer() {
        delete ptr;  // Automatically deletes the object when the smart pointer is destroyed
    }

    // Delete copy constructor and assignment operator (No copying allowed)
    /* 
        Why const is important?
        It would not prevent assignments from const UniquePointer objects.
        ex:
            UniquePointer<int> up1(new int(42));
            UniquePointer<int> up2(new int(100));

            const UniquePointer<int> up3(new int(55));

            // up1 = up2;  // Error: Copy assignment is deleted (as expected)
            up1 = up3;    // This would compile because const isn't handled!
     */
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    // Move constructor (transfers ownership)
    /* 
         If an operation can throw an exception, containers avoid using it to maintain internal consistency and fall back to copying instead.
     */
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
    UniquePointer<int> uptr(new int(42)); // new int(42) means dynamically allocate memory for integer
    // UniquePointer<int> uptr = new int(42); // new int(42) means dynamically allocate memory for integer
    // int *tmp = 42; // error: cannot initialize a variable of type 'int *' with an rvalue of
    // UniquePointer<int> uptr(tmp);
    
    std::cout << *uptr << std::endl;

    // UniquePointer<int> uptr2 = uptr;  // Compilation error due to deleted copy constructor
    UniquePointer<int> uptr2(std::move(uptr)); 
    // UniquePointer<int> uptr2 = std::move(uptr);  // Ownership transferred
    std::cout << *uptr2 << std::endl;
    std::cout << uptr2->aa() << std::endl;

    return 0;
}
