#include <iostream>
#include <thread>
#include <vector>

// A simple function that will be run by multiple threads
void printMessage(int threadID, int numIterations) {
    for (int i = 0; i < numIterations; ++i) {
        std::cout << "Thread " << threadID << " is working on iteration " << i << std::endl;
    }
}

int main() {
    const int numThreads = 4;
    const int numIterations = 5;

    // Vector to store the threads
    std::vector<std::thread> threads;

    // Creating multiple threads
    for (int i = 0; i < numThreads; ++i) {
        // Each thread runs the printMessage function
        threads.push_back(std::thread(printMessage, i, numIterations));
    }

    // Join threads to the main thread (wait for all threads to finish)
    for (auto& th : threads) {
        th.join(); // Ensures the main thread waits for each thread to complete
    }

    std::cout << "All threads completed." << std::endl;

    return 0;
}
