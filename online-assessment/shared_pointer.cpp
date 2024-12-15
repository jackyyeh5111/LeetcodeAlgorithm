#include <iostream>

using namespace std;

template <typename T>
class SharedPointer {
private:
    T* ptr; // ptr to managed object
    std::atomic<int>* ref_count;

    void release() {
        (*ref_count)--;
        if (*ref_count == 0) {    
            delete ptr;
            delete ref_count;
            std::cout << "release managed object\n";
        }
        ptr = nullptr;
        ref_count = nullptr;
    }
public:
     // default constructor
    explicit SharedPointer(T* p = nullptr) : ptr(p), ref_count(new std::atomic<int>(1)) {}
    SharedPointer() = delete;
    
    // copy constructor
    SharedPointer(const SharedPointer& other) : ptr(other.ptr), ref_count(other.ref_count) {
        (*ref_count)++;
    }

    // move constructor
    SharedPointer(SharedPointer&& other) : ptr(other.ptr), ref_count(other.ref_count) {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    // deconstructor
    ~SharedPointer() {
        release();
    }
    // copy assignment
    SharedPointer& operator=(const SharedPointer& other) {
        if (this == &other) return *this;  // Avoid self-assignment

        release();
        ptr = other.ptr;
        ref_count = other.ref_count;
        (*ref_count)++;
        return *this;
    }
    // move assignment
    // move constructor vs. move assignment: need release in move assignment
    SharedPointer& operator=(SharedPointer&& other) {
        if (this == &other) return *this;  // Avoid self-assignment

        release();
        ptr = other.ptr;
        ref_count = other.ref_count;
        other.ptr = nullptr;
        other.ref_count = nullptr;

        return *this;
    }

    // dereference
    T& operator*() {
        return *ptr;
    }
    // arrow operator  
    T* operator->() {
        return ptr;
    }

    int use_count() const {
        return *ref_count;
    }
};

// Usage Example
int main() {
  SharedPointer<int> sp1(new int(42));
  std::cout << "Value: " << *sp1 << ", Reference Count: " << sp1.use_count()
            << std::endl;

  // sp1 = std::move(sp1);  

  {
    SharedPointer<int> sp2 = sp1;  // Copy constructor
    std::cout << "Value: " << *sp2 << ", Reference Count: " << sp1.use_count()
              << std::endl;
  }  // sp2 goes out of scope here, ref_count decrements

  std::cout << "Reference Count after sp2 goes out of scope: "
            << sp1.use_count() << std::endl;

  return 0;
}
