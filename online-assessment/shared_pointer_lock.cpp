#include <iostream>
#include <mutex>
using namespace std;

template <typename T>
class SharedPointer {
  private:
    T* ptr;
    int* ref_count;
    mutable std::mutex mtx;
    void release() {
      std::lock_guard<std::mutex> lock(mtx);
      (*ref_count)--;
      if (*ref_count == 0) {
        delete ptr;
        delete ref_count;
      }
      ptr = nullptr;
      ref_count = nullptr;
    }
  public:
    // default constructor
    SharedPointer() = delete;
    // constructor passing ptr
    SharedPointer(T* ptr) : ptr(ptr), ref_count(new int(1)) {}

    // deconstructor
    ~SharedPointer() {
      release();
    }

    // copy constructor
    SharedPointer(const SharedPointer& other) : ptr(other.ptr), ref_count(other.ref_count) {
      std::lock_guard<std::mutex> lock(mtx);
      (*ref_count)++;
    }
    // move constructor
    SharedPointer(SharedPointer&& other) : ptr(other.ptr), ref_count(other.ref_count) {
      std::lock_guard<std::mutex> lock(mtx);
      other.ptr = nullptr;
      other.ref_count = nullptr;
    }
    // copy assignemnt
    SharedPointer& operator=(const SharedPointer& other) {
      if (this == &other) return *this; // avoid self copying
      release();
      std::lock_guard<std::mutex> lock(mtx);
      ptr = other.ptr;
      ref_count = other.ref_count;
      (*ref_count)++;
      return *this;
    }
    // move assignemnt
    SharedPointer& operator=(SharedPointer&& other) {
      if (this == &other) return *this; // avoid self copying
      release();
      ptr = other.ptr;
      ref_count = other.ref_count;
      other.ptr = nullptr;
      other.ref_count = nullptr;
      return *this;
    }
    // overload * operator
    T& operator*() {
      return *ptr;
    }
    // overload -> operator
    T* operator->() {
      return ptr;
    }

    int use_count() const {
      std::lock_guard<std::mutex> lock(mtx);
      return ref_count ? *ref_count : 0;
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
