#include <iostream>
#include <cstring>  // For strlen, strcpy

class String {
 private:
  char* data;    // Pointer to store the string's characters
  size_t size;   // Size of the string (excluding null-terminator)

 public:
  // Default Constructor
  String() : data(new char[1]), size(0) {
    data[0] = '\0';  // Initialize empty string
  }

  // Parameterized Constructor (from C-string)
  String(const char* str) : size(strlen(str)) {
    data = new char[size + 1];    // Allocate memory for string
    strcpy(data, str);            // Copy string content
  }

  // Copy Constructor
  String(const String& other) : size(other.size) {
    data = new char[size + 1];    // Allocate memory for copy
    strcpy(data, other.data);     // Copy data
  }

  // Move Constructor
  String(String&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;   // Nullify the moved-from object's data
    other.size = 0;
  }

  // Copy Assignment Operator
  String& operator=(const String& other) {
    if (this != &other) {
      delete[] data;         // Clean up current data

      size = other.size;
      data = new char[size + 1];  // Allocate new memory
      strcpy(data, other.data);   // Copy string content
    }
    return *this;
  }

  // Move Assignment Operator
  String& operator=(String&& other) noexcept {
    if (this != &other) {
      delete[] data;        // Clean up current data

      data = other.data;    // Steal data pointer
      size = other.size;

      other.data = nullptr;  // Nullify the moved-from object
      other.size = 0;
    }
    return *this;
  }

  // Destructor
  ~String() {
    delete[] data;  // Free allocated memory
  }

  // Get length of the string
  size_t length() const {
    return size;
  }

  // Concatenation operator
  String operator+(const String& other) const {
    String result;                             // Create an empty string
    result.size = size + other.size;           // New size is sum of both strings
    result.data = new char[result.size + 1];   // Allocate memory for concatenation

    strcpy(result.data, data);                 // Copy first string
    strcat(result.data, other.data);           // Concatenate second string

    return result;
  }

  // Equality operator
  bool operator==(const String& other) const {
    return strcmp(data, other.data) == 0;
  }

  // Inequality operator
  bool operator!=(const String& other) const {
    return !(*this == other);
  }

  // Output stream operator for easy printing
  friend std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.data;
    return os;
  }

  // Access character at index
  char& operator[](size_t index) {
    return data[index];
  }

  const char& operator[](size_t index) const {
    return data[index];
  }

  // Clear the string
  void clear() {
    delete[] data;
    data = new char[1];
    data[0] = '\0';
    size = 0;
  }

  // Return the raw C-string
  const char* c_str() const {
    return data;
  }
};

// Example Usage
int main() {
  String str1("Hello");
  String str2(" World!");

  std::cout << "str1: " << str1 << ", Length: " << str1.length() << std::endl;
  std::cout << "str2: " << str2 << ", Length: " << str2.length() << std::endl;

  String str3 = str1 + str2;  // Concatenation
  std::cout << "str3: " << str3 << ", Length: " << str3.length() << std::endl;

  String str4 = str3;         // Copy constructor
  std::cout << "str4 (copy of str3): " << str4 << std::endl;

  str4[6] = 'w';  // Modify character at index
  std::cout << "Modified str4: " << str4 << std::endl;

  str4.clear();   // Clear the string
  std::cout << "Cleared str4: " << str4 << ", Length: " << str4.length() << std::endl;

  return 0;
}
