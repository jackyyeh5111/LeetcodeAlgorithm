#include <chrono>
#include <iostream>
#include <shared_mutex>
#include <thread>
#include <vector>

class SharedData {
 private:
  std::vector<int> data;  // Shared resource

  // mutable: particularly useful for classes that provide read-only access to
  // some members but still need to perform locking or other operations that
  // modify state internally.
  mutable std::shared_mutex mutex;  // Mutex for synchronizing access

 public:
  void add(int value) {
    std::unique_lock<std::shared_mutex> lock(mutex);  // Acquire exclusive lock
    data.push_back(value);
    std::cout << "Added: " << value << std::endl;
  }

  void read() const {
    std::shared_lock<std::shared_mutex> lock(mutex);  // Acquire shared lock
    std::cout << "Reading data: ";
    for (const auto& value : data) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }
};

// Function for writer threads
void writer(SharedData& sharedData, int value) {
  sharedData.add(value);
  std::this_thread::sleep_for(
      std::chrono::milliseconds(100));  // Simulate some work
}

// Function for reader threads
void reader(const SharedData& sharedData) {
  sharedData.read();
  std::this_thread::sleep_for(
      std::chrono::milliseconds(50));  // Simulate some work
}

int main() {
  SharedData sharedData;

  // Create writer threads
  std::thread w1(writer, std::ref(sharedData), 1);
  std::thread w2(writer, std::ref(sharedData), 2);

  // Create reader threads
  std::thread r1(reader, std::cref(sharedData));
  std::thread r2(reader, std::cref(sharedData));
  std::thread r3(reader, std::cref(sharedData));

  // Join threads
  w1.join();
  w2.join();
  r1.join();
  r2.join();
  r3.join();

  return 0;
}
