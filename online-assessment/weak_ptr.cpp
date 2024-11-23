#include <iostream>
#include <memory>

class B; // Forward declaration

class A {
public:
    std::weak_ptr<B> ptrB;  // Shared pointer to B
    A() { std::cout << "A created\n"; }
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::shared_ptr<A> ptrA;  // Shared pointer to A
    B() { std::cout << "B created\n"; }
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    {
        std::shared_ptr<A> a = std::make_shared<A>();
        std::shared_ptr<B> b = std::make_shared<B>();

        // Creating circular reference
        a->ptrB = b;
        b->ptrA = a;

        // At this point, both `a` and `b` have shared pointers to each other.
        // Reference count for `a` and `b` never reaches zero.
    }  // Memory leak! Neither A nor B is destroyed.

    std::cout << "End of scope\n";
    return 0;
}
