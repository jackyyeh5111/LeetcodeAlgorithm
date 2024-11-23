#include <iostream>
#include <string_view>
#include <string> 

static uint32_t s_alloc_cnt = 0;
void* operator new(size_t size) {
    s_alloc_cnt++;
    std::cout << "allocate " << size << " bytes\n";
    return malloc(size);
}

void printStringView(std::string_view sv) {
    std::cout << "String view content: " << sv << "\n";
}

int main() {
    // Original string
    std::string fullString = "Hello, world!";

    // // Create a string_view that references the original string
    // std::string_view sv(fullString);

    // // Print the string_view
    // printStringView(sv);

    // // Create a substring view (first 5 characters)
    // std::string_view subView = sv.substr(0, 5);

    // // Print the substring view
    // std::cout << "Substring view content: " << subView << "\n";

    // // Demonstrating that string_view is non-owning
    // fullString[7] = 'W';  // Modify the original string

    // // Print the string_view again to show the change is reflected
    // std::cout << "Modified string view content: " << sv << "\n";

    return 0;
}
