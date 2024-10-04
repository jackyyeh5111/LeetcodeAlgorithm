/*
    ### Questions ###

    We are looking for a program that manages “intensity” by segments. Segments
    are intervals from -infinity to infinity, we liked you to implement
   functions that updates intensity by an integer amount for a given range. All
   intensity starts with 0. Please implement these two functions:

        add(from, to, amount)
        set(from, to, amount)

    You should implement the functions based on your own interpretation of the
    problem and document any assumptions you make.

    Here is an example sequence (data stored as an array of start point and
    value for each segment.):

        Start: []
        Call: add(10, 30, 1) => [[10,1],[30,0]]
        Call: add(20, 40, 1) => [[10,1],[20,2],[30,1],[40,0]]
        Call: add(10, 40, -2) => [[10,-1],[20,0],[30,-1],[40,0]]

        Start: []
        Call: add(10, 30, 1) => [[10,1],[30,0]]
        Call: add(20, 40, 1) => [[10,1],[20,2],[30,1],[40,0]]
        Call: add(10, 40, -1) => [[20,1],[30,0]]
        Call: add(10, 40, -1) => [[10,-1],[20,0],[30,-1],[40,0]]


        Call: add(10, 30, 1) => [[10,1], [15,1], [30,0]]
            - leave previous only
            - begin != 0

    ### Assumptions ###
        1. Segments are defined by two points [from, to), where the intensity
   changes within the half-open interval.
        2. add(from, to, amount) will increase the intensity within the given
   range.
        3. set(from, to, amount) will set the intensity within the given range,
   disregarding previous values.
        4. Do nothing if parameter from >= to.
        5. Segments got unlimited size.
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
    // get first element that <= key in segments in O(logn)
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

  return 0;
}
