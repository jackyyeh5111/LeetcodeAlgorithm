/* 
  Question:
    We are looking for a program that manages “intensity” by segments. Segments are intervals from -infinity to infinity, we liked you to implement functions that updates intensity by an integer amount for a given range. All intensity starts with 0. Please implement these two functions:

    add(from, to, amount)  
    set(from, to, amount)
    You should implement the functions based on your own interpretation of the problem and document any assumptions you make. 

    Here is an example sequence (data stored as an array of start point and value for each segment.):
    Start: []
    Call: add(10, 30, 1) => [[10,1],[30,0]]
    Call: add(20, 40, 1) => [[10,1],[20,2],[30,1],[40,0]]
    Call: add(10, 40, -2) => [[10,-1],[20,0],[30,-1],[40,0]]

    Start: []
    Call: add(10, 30, 1) => [[10,1],[30,0]]
    Call: add(20, 40, 1) => [[10,1],[20,2],[30,1],[40,0]]
    Call: add(10, 40, -1) => [[20,1],[30,0]]
    Call: add(10, 40, -1) => [[10,-1],[20,0],[30,-1],[40,0]]
 */
/*
    Overview:
      This C++ code defines a SegmentManager class that manages the intensity of 
      segments within specified ranges. The key operations are add and set, which 
      modify the intensity of values within a half-open interval [from, to). 
      Intensities are stored using a std::map where the keys represent segment boundaries, 
      and the values are the intensities at those points.

    Reason I use std::map to represent segments:
      std::map maintains keys in sorted order, enabling quick lookups, 
      modifications, and erase in logarithmic time O(logn). 
      It allows for sparse representation of ranges, storing only key boundary 
      points where changes occur, which minimizes memory usage. 

    Assumptions:
        1. Segments are defined by two points [from, to), where the intensity
           changes within the half-open interval.
        2. add(from, to, amount) will increase the intensity within the given
           range.
        3. set(from, to, amount) will set the intensity within the given range,
           disregarding previous values.
        4. Segments have unlimited size.
        5. Do nothing if parameter value from >= to.
 */
#include <iostream>
#include <map>

class SegmentManager {
 private:
  std::map<int, int> segments;

 public:
  SegmentManager() {}
  void add(int from, int to, int amount) { modify(from, to, amount, true); }
  void set(int from, int to, int amount) { modify(from, to, amount, false); }
  void clear() { segments.clear(); }
  void printSegments() {
    std::cout << "[";
    for (auto it = segments.begin(); it != segments.end(); ++it) {
      std::cout << "[" << it->first << "," << it->second << "]";
      if (next(it) != segments.end()) std::cout << ",";
    }
    std::cout << "]" << std::endl;
  }

 private:
  // Inserts a key into the segment map if it doesn't exist
  // Initializes its value based on previous segment or 0 if it's the first segment
  void insertEntry(int key) {
    // get first element that <= key in segments.
    // lower_bound in map can find key in O(logn)
    auto it_start = segments.lower_bound(key);
    if (it_start == segments.begin()) {  // insert at begin
      if (segments.empty() || it_start->first != key) segments[key] = 0;
    } else if (it_start == segments.end()) {  // insert at end
      segments[key] = 0;
    } else if (it_start->first != key) {  // insert at middle
      if (it_start->first != key) segments[key] = std::prev(it_start)->second;
    }
  }

  // Removes redundant entries where consecutive segments have the same intensity
  void removeRedundantEntries(const std::map<int, int>::iterator &it_start,
                              const std::map<int, int>::iterator &it_end) {
    auto iter = it_start;
    auto next_end = std::next(it_end);

    while (iter != next_end) {
      if (iter == segments.begin()) {  // Skip the first element
        ++iter;
        continue;
      }

      // If the current intensity is the same as the previous one, it's redundant
      if (iter->second == std::prev(iter)->second) {
        iter = segments.erase(iter);  // Erase and move to the next valid iterator
      } else {
        ++iter;
      }
    }
  }

  void removeZeroStartEntry() {
    auto iter = segments.begin();
    while (iter != segments.end() && iter->second == 0) {
      iter = segments.erase(iter);  // Erase and move to the next valid iterator
    }
  }

  void modify(int from, int to, int amount, bool isAdd) {
    if (from >= to) return;

    // Ensure both boundary entries exist in the map
    insertEntry(from);
    insertEntry(to);

    // Apply changes to the range [from, to)
    auto it_start = segments.lower_bound(from);
    auto it_end = segments.lower_bound(to);
    for (auto iter = it_start; iter != it_end; ++iter) {
      if (isAdd) {
        iter->second += amount;
      } else {
        iter->second = amount;
      }
    }

    // Clean up redundant entries where consecutive segments have the same
    removeRedundantEntries(it_start, it_end);

    // Remove starting entries if they have value 0
    removeZeroStartEntry();
  }
};

int main() {
  SegmentManager manager;

  // Test cases as described
  manager.printSegments();  // Start: []

  std::cout << "\n--- test case 1 ----\n\n";
  manager.clear();
  manager.add(10, 30, 1);   // Call: add(10, 30, 1)
  manager.printSegments();  // Expected: [[10,1],[30,0]]
  manager.add(20, 40, 1);   // Call: add(20, 40, 1)
  manager.printSegments();  // Expected: [[10,1],[20,2],[30,1],[40,0]]
  manager.add(10, 40, -2);  // Call: add(10, 40, -2)
  manager.printSegments();  // Expected: [[10,-1],[20,0],[30,-1],[40,0]]

  std::cout << "\n--- test case 2 ----\n\n";
  manager.clear();
  manager.add(10, 30, 1);
  manager.printSegments();
  manager.add(20, 40, 1);
  manager.printSegments();
  manager.add(10, 40, -1);
  manager.printSegments();
  manager.add(10, 40, -1);
  manager.printSegments();

  std::cout << "\n--- test case 3 ----\n\n";
  manager.clear();
  manager.add(10, 30, 0);
  manager.printSegments();
  manager.add(1, 10, 1);
  manager.printSegments();
  manager.set(5, 9, 2);
  manager.printSegments();
  manager.add(6, 10, 2);
  manager.printSegments();
  manager.set(-1, 3, 0);
  manager.printSegments();

  return 0;
}
