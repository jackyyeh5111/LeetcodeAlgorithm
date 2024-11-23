#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

class Semaphore {
public:
    Semaphore(int count = 0) : count(count) {}

    void wait() {
        std::unique_lock<std::mutex> lock(mutex);
        // Decrease the count and wait if it is less than zero
        while (count <= 0) {
            condition.wait(lock);
        }
        count--;
    }

    void signal() {
        std::lock_guard<std::mutex> lock(mutex);
        count++;
        condition.notify_one(); // Notify one waiting thread
    }

private:
    std::mutex mutex;
    std::condition_variable condition;
    int count;
};

void worker(int id, Semaphore& semaphore) {
    std::cout << "Worker " << id << " is waiting to enter the critical section." << std::endl;
    semaphore.wait(); // Wait for the semaphore

    // Critical section
    std::cout << "Worker " << id << " has entered the critical section." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    std::cout << "Worker " << id << " is leaving the critical section." << std::endl;

    semaphore.signal(); // Signal the semaphore
}

int main() {
    const int numWorkers = 5;
    const int maxConcurrent = 2; // Maximum number of concurrent threads
    Semaphore semaphore(maxConcurrent); // Create a semaphore with a maximum count

    std::thread workers[numWorkers];

    for (int i = 0; i < numWorkers; ++i) {
        workers[i] = std::thread(worker, i + 1, std::ref(semaphore));
    }

    for (auto& worker : workers) {
        worker.join(); // Wait for all workers to finish
    }

    return 0;
}
