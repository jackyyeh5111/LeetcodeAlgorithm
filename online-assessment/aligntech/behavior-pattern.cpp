#include <iostream>
#include <vector>
#include <algorithm>

// Strategy Interface
class SortStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0; // Pure virtual function
    virtual ~SortStrategy() {}
};

// Concrete Strategy 1: Bubble Sort
class BubbleSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Bubble Sort: ";
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data.size() - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }
};

// Concrete Strategy 2: Quick Sort
class QuickSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Quick Sort: ";
        std::sort(data.begin(), data.end());  // Using C++'s built-in quicksort
    }
};

// Context: This class uses a strategy to perform sorting
class SortContext {
private:
    SortStrategy* strategy;  // The current sorting strategy

public:
    SortContext(SortStrategy* strategy) : strategy(strategy) {}

    void setStrategy(SortStrategy* newStrategy) {
        strategy = newStrategy;
    }

    void executeStrategy(std::vector<int>& data) {
        strategy->sort(data);
    }
};

int main() {
    std::vector<int> data = {5, 3, 8, 1, 2};

    // Using BubbleSort strategy
    SortContext context(new BubbleSort());
    context.executeStrategy(data);
    for (int num : data) std::cout << num << " ";
    std::cout << std::endl;

    // Changing to QuickSort strategy
    context.setStrategy(new QuickSort());
    context.executeStrategy(data);
    for (int num : data) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
