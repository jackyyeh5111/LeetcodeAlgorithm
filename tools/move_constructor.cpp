/* 
    What's difference between constructor 1 & 2?
    While both constructors are "stealing other object", however, the second
    constructor allows object as a rvalue. For instance:
        1. str2 = create_str() // return value of function is a rvalue
        2. str2 = std::move(str1)

    // constructor 1
    MyString(MyString& other) noexcept {
        std::cout << "Move Constructor called\n";
        data = other.data;      
        other.data = nullptr;   
    }

    // constructor 2
    MyString(MyString&& other) noexcept {
        std::cout << "Move Constructor called\n";
        data = other.data;      
        other.data = nullptr;   
    }


    // Another example using move semantics: Function that returns an object by value
    MyString createString() {
        MyString str("Hello, World!");
        return std::move(str);  // Move constructor will be called in C++11
    }
    MyString str = createString();

 */
#include <iostream>
#include <cstring>
using namespace std;
class MyString {
private:
    char* data;

public:
    // Constructor
    MyString(const char* str = "") {
        std::cout << "Constructor called\n";
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
    }

    // Copy Constructor (deep copy)
    MyString(const MyString& other) {
        std::cout << "Copy Constructor called\n";
        data = new char[std::strlen(other.data) + 1];
        std::strcpy(data, other.data);
    }

    // Move Constructor (steals resources) takes an rvalue reference (Type&&).
    MyString(MyString&& other) noexcept {
        std::cout << "Move Constructor called\n";
        data = other.data;      
        other.data = nullptr;   
    }

    // Destructor
    ~MyString() {
        std::cout << "Destructor called\n";
        delete[] data;
    }

    // Print function
    void print() const {
        if (data)
            std::cout << "Data: " << data << "\n";
        else
            std::cout << "Data is null\n";
    }
};

int main() {
    // MyString str1("Hello, World!");
    // // MyString str2 = std::move(str1);  // Move constructor is called
    // MyString str2 = str1;  // copy constructor is called

    // std::cout << "str1: ";
    // str1.print();  // str1 is now empty (data is null)

    // std::cout << "str2: ";
    // str2.print();  // str2 has the original data

    string str1 = "aaa";
    string str2 = std::move(str1);
    std::cout << "str1: " << str1 << '\n';
    std::cout << "str2: " << str2 << '\n';
    return 0;
}
