#include <iostream>
#include <string>

class MyString {
private:
    char* data;

public:
    MyString(const char* str) {
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
        std::cout << "Constructor called\n";
    }

    // Move Constructor
    MyString(MyString&& other) noexcept {
        std::cout << "Move Constructor called\n";
        data = other.data;       // Transfer ownership of the resource
        other.data = nullptr;    // Leave the source in a valid, empty state
    }

    ~MyString() { 
        delete[] data; 
        std::cout << "Destructor called\n";
    }

    // Print function
    void print() const {
        std::cout << data << '\n';
    }
};

// Function that returns an object by value
MyString createString() {
    MyString str("Hello, World!");
    return std::move(str);  // Move constructor will be called in C++11
}

int main() {
    MyString s = createString();  // Move constructor is called here
    s.print();
    return 0;
}
