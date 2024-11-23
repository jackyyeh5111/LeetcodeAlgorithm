#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

// Custom Pair class
// class PairOri {
// public:
//     int first, second;

//     // Constructor to initialize first and second
//     Pair(int a = 0, int b = 0) : first(a), second(b) {}

//     // Overloading < operator for sorting in reverse order of std::pair
//     bool operator<(const Pair& other) const {
//         if (first != other.first) return first > other.first;
//         return second > other.second;
//     }

//     // Overloading + operator for accumulation
//     Pair operator+(const Pair& other) const {
//         return Pair(first + other.first, second + other.second);
//     }

//     // Overloading - operator for adjacent difference
//     Pair operator-(const Pair& other) const {
//         return Pair(first - other.first, second - other.second);
//     }
// };

class Pair {
public:
    int first, second;

    // Constructor to initialize first and second
    Pair(int a=0, int b=0) : first(a), second(b) {}
    // Overloading < operator for sorting in reverse order of std::pair
    bool operator<(const Pair& other) const {
        if (first == other.first)
            return second > other.second;
        return first > other.first;
    }

    // Overloading + operator for accumulation
    Pair operator+(const Pair & other) const {
        return Pair(first + other.first, second + other.second);
    }
    // Overloading - operator for adjacent difference
    Pair operator-(const Pair & other) const {
        return Pair(first - other.first, second - other.second);
    }
};

// Function to print a vector of Pair objects
void printPairs(const std::vector<Pair>& pairs) {
    for (const auto& p : pairs) {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    std::vector<Pair> arr = { {3, 5}, {1, 2}, {4, 8}, {2, 3} };

    // Sorting in reverse order
    std::sort(arr.begin(), arr.end());
    std::cout << "Sorted Pairs: ";
    printPairs(arr);

    // Using std::accumulate to find the sum of Pair objects
    Pair sum = std::accumulate(arr.begin(), arr.end(), Pair(0, 0));
    std::cout << "Sum of Pairs: (" << sum.first << ", " << sum.second << ")\n";

    // Using std::adjacent_difference to find the differences
    std::vector<Pair> res(arr.size());
    std::adjacent_difference(arr.begin(), arr.end(), res.begin());
    std::cout << "Adjacent Differences: ";
    printPairs(res);

    return 0;
}
