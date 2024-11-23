#include <iostream>

using namespace std;

template <typename T>
class SharedPointer {
 private:
  T* ptr;  // ptr to managed object
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
  SharedPointer(T* p = nullptr) : ptr(p), ref_count(new std::atomic<int>(1)) {}

  // copy constructor
  SharedPointer(const SharedPointer& other)
      : ptr(other.ptr), ref_count(other.ref_count) {
    (*ref_count)++;
  }

  // move constructor
  SharedPointer(SharedPointer&& other)
      : ptr(other.ptr), ref_count(other.ref_count) {
    other.ptr = nullptr;
    other.ref_count = nullptr;
  }

  // deconstructor
  ~SharedPointer() { release(); }
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
  T& operator*() { return *ptr; }
  // arrow operator
  T* operator->() { return ptr; }

  int use_count() const { return *ref_count; }
};

class Base {
 public:
  virtual void func() { cout << "Base\n"; }
};
class Derived : public Base {
 public:
  void func() override { cout << "Derived\n"; }
};
// void callFunc(Base & b) { b.func(); }
// void callFunc(Base* b) { b->func(); }
void callFunc(Base &b) { b.func(); }

// Usage Example
int main() {

//   Derived d;
    Base*  obj = new Derived(); // object slicing
  callFunc(*obj);  // Output: "Derived"

  return 0;
}
