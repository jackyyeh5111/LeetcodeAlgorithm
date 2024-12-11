#include <iostream>

#define TEST 1
#if TEST == 0
// General template
template <typename T>
class Example {
public:
    void display() {
        std::cout << "General template" << std::endl;
    }
};

// Full specialization for int
template <>
class Example<int> {
public:
    void display() {
        std::cout << "Specialized template for int" << std::endl;
    }
};

int main() {
    Example<double> obj1; // Uses general template
    Example<int> obj2;    // Uses specialized template
    obj1.display();       // Output: General template
    obj2.display();       // Output: Specialized template for int
    return 0;
}
#endif

#if TEST == 1
// General template
template <typename T1, typename T2>
class Pair {
public:
    void display() {
        std::cout << "General template" << std::endl;
    }
};

// Partial specialization for when both types are the same
template <typename T>
class Pair<T, T> {
public:
    void display() {
        std::cout << "Partial specialization: Same types" << std::endl;
    }
};

int main() {
    Pair<int, double> obj1; // Uses general template
    Pair<int, int> obj2;    // Uses partial specialization
    obj1.display();         // Output: General template
    obj2.display();         // Output: Partial specialization: Same types
    return 0;
}
#endif

/* 
    real-world example for template specialization
 */
#if TEST == 3
template <typename T>
void print_elements(const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Full specialization for pointers (e.g., for raw pointers)
template <typename T>
void print_elements(const std::vector<T*>& vec) {
    for (const auto& elem : vec) {
        if (elem) {
            std::cout << *elem << " ";
        } else {
            std::cout << "nullptr ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = {1, 2, 3};
    print_elements(vec);  // Regular print

    std::vector<int*> ptr_vec = {new int(10), nullptr, new int(30)};
    print_elements(ptr_vec);  // Specialized print for pointers
}
#endif