/* 
    ref: Stop using std::vector wrong
        https://www.youtube.com/watch?v=Xx-NcqmveDc
 */
#include <iostream>
#include <vector>

using namespace std;

static int s_AllocationCount = 0;
static int s_CopyCount = 0;
static int s_MoveCount = 0;

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
    // Data() : value(0) {}
    Data(int val) : value(val) {}
    Data(const Data& other) : value(other.value) {
        s_CopyCount++;
    }
    Data(Data&& other) : value(other.value) {
        s_MoveCount++;
    }
};

int main() {
    int num_data = 10;
    std::vector<Data> vec;
    vec.reserve(10);
    for (int i = 0; i < num_data; i++) {
        // vec.push_back(Data(i));
        // vec.push_back(Data(i));
        vec.emplace_back(i);
    }

    std::cout << "allocation " << s_AllocationCount << " times\n";
    std::cout << "copy  " << s_CopyCount << " times\n";
    std::cout << "move  " << s_MoveCount << " times\n";

    return 0;
}
