#include <iostream>
#include <stdexcept>  // For exceptions

template <typename T>
class Vector {
 private:
  T* data;           // Pointer to the array storing the elements
  size_t capacity;   // The total allocated space
  size_t size;       // The number of elements currently in the vector

  // Helper function to grow the internal storage
  void resize_capacity(size_t new_capacity) {
    T* new_data = new T[new_capacity];  // Allocate new memory

    // Move the old elements to the new storage
    for (size_t i = 0; i < size; ++i) {
      new_data[i] = std::move(data[i]);
    }

    delete[] data;      // Free the old memory
    data = new_data;    // Point to the new storage
    capacity = new_capacity;
  }

 public:
  // Default constructor
  Vector() : data(nullptr), capacity(0), size(0) {}

  // Constructor with initial capacity
  explicit Vector(size_t initial_capacity) 
      : data(new T[initial_capacity]), capacity(initial_capacity), size(0) {}

  // Destructor
  ~Vector() {
    delete[] data;  // Free the allocated memory
  }

  // Copy constructor
  Vector(const Vector& other) : data(new T[other.capacity]), capacity(other.capacity), size(other.size) {
    for (size_t i = 0; i < size; ++i) {
      data[i] = other.data[i];  // Copy elements
    }
  }

  // Move constructor
  Vector(Vector&& other) noexcept : data(other.data), capacity(other.capacity), size(other.size) {
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
  }

  // Copy assignment operator
  Vector& operator=(const Vector& other) {
    if (this != &other) {
      delete[] data;  // Free current memory

      capacity = other.capacity;
      size = other.size;
      data = new T[capacity];

      for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];  // Copy elements
      }
    }
    return *this;
  }

  // Move assignment operator
  Vector& operator=(Vector&& other) noexcept {
    if (this != &other) {
      delete[] data;  // Free current memory

      data = other.data;
      capacity = other.capacity;
      size = other.size;

      other.data = nullptr;
      other.capacity = 0;
      other.size = 0;
    }
    return *this;
  }

  // Access element by index (with bounds checking)
  T& operator[](size_t index) {
    if (index >= size) {
      throw std::out_of_range("Index out of bounds");
    }
    return data[index];
  }

  const T& operator[](size_t index) const {
    if (index >= size) {
      throw std::out_of_range("Index out of bounds");
    }
    return data[index];
  }

  // Add an element to the end
  void push_back(const T& value) {
    if (size == capacity) {
      resize_capacity(capacity == 0 ? 1 : capacity * 2);  // Double the capacity if full
    }
    data[size++] = value;  // Add the element and increment size
  }

  // Add an element to the end using move semantics
  void push_back(T&& value) {
    if (size == capacity) {
      resize_capacity(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = std::move(value);  // Add the element and increment size
  }

  // Remove the last element
  void pop_back() {
    if (size > 0) {
      --size;
    }
  }

  // Return the number of elements
  size_t get_size() const {
    return size;
  }

  // Return the total capacity of the vector
  size_t get_capacity() const {
    return capacity;
  }

  // Clear the vector (remove all elements)
  void clear() {
    size = 0;
  }

  // Check if the vector is empty
  bool empty() const {
    return size == 0;
  }

  // Access the first element
  T& front() {
    if (size == 0) {
      throw std::out_of_range("Vector is empty");
    }
    return data[0];
  }

  const T& front() const {
    if (size == 0) {
      throw std::out_of_range("Vector is empty");
    }
    return data[0];
  }

  // Access the last element
  T& back() {
    if (size == 0) {
      throw std::out_of_range("Vector is empty");
    }
    return data[size - 1];
  }

  const T& back() const {
    if (size == 0) {
      throw std::out_of_range("Vector is empty");
    }
    return data[size - 1];
  }
};

// Example usage
int main() {
  Vector<int> vec;

  // Adding elements
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);

  std::cout << "Vector size: " << vec.get_size() << ", capacity: " << vec.get_capacity() << std::endl;

  // Accessing elements
  std::cout << "First element: " << vec.front() << std::endl;
  std::cout << "Last element: " << vec.back() << std::endl;

  // Modifying elements
  vec[1] = 50;
  std::cout << "Modified second element: " << vec[1] << std::endl;

  // Removing the last element
  vec.pop_back();
  std::cout << "After pop_back, size: " << vec.get_size() << std::endl;

  // Iterating over the vector
  std::cout << "Vector elements: ";
  for (size_t i = 0; i < vec.get_size(); ++i) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
