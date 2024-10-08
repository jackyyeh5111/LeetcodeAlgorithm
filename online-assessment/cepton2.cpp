#include <iostream>
#include <map>

class IntensityManager {
public:
    // Adds the 'amount' to all intensities in the range [from, to)
    void add(int from, int to, int amount) {
        intensity[from] += amount;
        intensity[to] -= amount;
        mergeSegments();  // Clean up any unnecessary zero transitions
    }

    // Sets the intensity to 'amount' in the range [from, to)
    void set(int from, int to, int amount) {
        // First zero out the range
        zeroOutRange(from, to);
        // Then apply the 'add' operation
        add(from, to, amount);
    }

    // Display the current state of intensity
    void display() {
        std::map<int, int> current = getActiveSegments();
        std::cout << "[";
        for (auto it = current.begin(); it != current.end(); ++it) {
            std::cout << "[" << it->first << "," << it->second << "]";
            if (std::next(it) != current.end()) std::cout << ",";
        }
        std::cout << "]\n";
    }

private:
    std::map<int, int> intensity;

    // Zero out intensities in the range [from, to)
    void zeroOutRange(int from, int to) {
        std::map<int, int> current = getActiveSegments();
        int prevIntensity = 0;
        for (auto it = current.begin(); it != current.end(); ++it) {
            if (it->first >= from && it->first < to) {
                add(it->first, to, -prevIntensity);
            }
            prevIntensity = it->second;
        }
    }

    // Get the actual active segments based on the intensity map
    std::map<int, int> getActiveSegments() {
        std::map<int, int> result;
        int currentValue = 0;
        for (const auto &p : intensity) {
            currentValue += p.second;
            result[p.first] = currentValue;
        }
        return result;
    }

    // Merge adjacent segments with zero intensity to simplify the map
    void mergeSegments() {
        std::map<int, int> newMap;
        int currentIntensity = 0;
        for (const auto& [point, change] : intensity) {
            currentIntensity += change;
            if (newMap.empty() || currentIntensity != 0) {
                newMap[point] = currentIntensity;
            }
        }
        intensity = std::move(newMap);
    }
};

int main() {
    IntensityManager manager;

    // Test Case 1
    std::cout << "Start: []\n";
    manager.add(10, 30, 1);
    std::cout << "Call: add(10, 30, 1) => ";
    manager.display();

    manager.add(20, 40, 1);
    std::cout << "Call: add(20, 40, 1) => ";
    manager.display();

    manager.add(10, 40, -2);
    std::cout << "Call: add(10, 40, -2) => ";
    manager.display();

    // Reset the manager
    manager = IntensityManager();
    std::cout << "\nStart: []\n";
    manager.add(10, 30, 1);
    std::cout << "Call: add(10, 30, 1) => ";
    manager.display();

    manager.add(20, 40, 1);
    std::cout << "Call: add(20, 40, 1) => ";
    manager.display();

    manager.add(10, 40, -1);
    std::cout << "Call: add(10, 40, -1) => ";
    manager.display();

    manager.add(10, 40, -1);
    std::cout << "Call: add(10, 40, -1) => ";
    manager.display();

    return 0;
}
