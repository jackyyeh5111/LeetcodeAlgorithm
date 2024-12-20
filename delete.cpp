#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

class ThreadSafeCounter {
  private:
    int counter ;
    mutable std::mutex mtx;
  public:
    ThreadSafeCounter() : counter(0) {}
    void increment() {
      std::lock_guard<std::mutex> lock(mtx);
      ++counter;
    }
    int getCount() const {
      std::lock_guard<std::mutex> lock(mtx);
      return counter;
    }
};

void worker(ThreadSafeCounter& counter, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        counter.increment();
    }
}

int main() {
    ThreadSafeCounter counter;
    int iterations = 10000;

    // Create multiple threads
    std::thread t1(worker, std::ref(counter), iterations);
    std::thread t2(worker, std::ref(counter), iterations);

    // t1.join();
    // t2.join();

    // Output the final counter value
    std::cout << "Final Counter Value: " << counter.getCount() << std::endl;

    return 0;
}
