#include <iostream>
#include <vector>

static int s_AllocationCount = 0;

// Overload new operator to monitor memory allocation
void* operator new(std::size_t size) {
    std::cout << "Allocating " << size << " bytes of memory.\n";
    s_AllocationCount ++;
    return malloc(size);
}

// Optional: Overload delete operator to track memory deallocation
// void operator delete(void* pointer) {
//     std::cout << "Deallocating memory.\n";
//     ::operator delete(pointer);
// }

struct Data {
    int value;

    // Default constructor
    Data() : value(0) {}

};

int main() {
    // Create instances using 'new' to invoke the overloaded operator
    Data* data1 = new Data();
    Data* data2 = new Data();

    // Clean up memory (to invoke the delete operator)
    delete data1;
    delete data2;

    std::cout << "allocation " << s_AllocationCount << " times\n";

    return 0;
}
