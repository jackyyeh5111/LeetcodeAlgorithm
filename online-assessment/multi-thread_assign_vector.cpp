#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

class VectorFiller {
public:
    static mutex mtx;

    // Function to fill part of the vector
    static void fillVector(vector<int>& nums, int start, int end) {
        for (int i = start; i < end; ++i) {
            unique_lock<mutex> lock(VectorFiller::mtx);
            nums[i] = i;
        }
    }
};

// Define static mutex outside the class!
mutex VectorFiller::mtx;



int main() {
    int size = 12; // The size of the vector to fill
    int numThreads = 4; // Number of threads to use

    vector<int> nums(size); // The vector to be filled

    // Calculate the range each thread will process
    int chunkSize = size / numThreads;
    vector<thread> threads;

    // Launch threads to fill the vector in parallel
    for (int i = 0; i < numThreads; ++i) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? size : start + chunkSize;
        threads.emplace_back(VectorFiller::fillVector, ref(nums), start, end);
    }

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    // Print the filled vector
    cout << "Filled vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
