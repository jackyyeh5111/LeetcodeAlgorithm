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
        4. Do nothing if parameter from >= to
 */
#include <iostream>
#include <map>

class SegmentManager {
 private:
  std::map<int, int> segments;

 public:
  SegmentManager() {}

  // Function to add intensity to a range [from, to)
  void add(int from, int to, int amount) { modify(from, to, amount, true); }

  // Function to set intensity to a value in a range [from, to)
  void set(int from, int to, int amount) { modify(from, to, amount, false); }

  // Print current segments
  void printSegments() {
    std::cout << "[";
    for (const auto& entry : segments) {
      std::cout << "[" << entry.first << "," << entry.second << "],";
    }
    std::cout << "]" << std::endl;
  }

 private:
  // Helper function to modify intensity, either by adding or setting values.
  void modify(int from, int to, int amount, bool isAdd) {
    // Ensure from < to
    if (from >= to) return;

    /*
        Call: add(10, 30, 1) => [[10,1],[30,0]]
        Call: add(20, 40, 1) => [[10,1],[20,2],[30,1],[40,0]]
        Call: add(10, 40, -2) => [[10,-1],[20,0],[30,-1],[40,0]]

        Call: add(10, 30, 1) => [[10,1], [30,0]]
        Call: add(10, 20, 1) => [[10,2], [20,1], [30,0]]
     */

    // Get the intensity value before `from`
    auto it_start = segments.lower_bound(from);
    if (it_start == segments.begin()) {
      if (segments.empty() || it_start->first != from) segments[from] = 0;
    } else if (it_start == segments.end()) {
      segments[from] = 0;
    } else if (it_start->first != from) {
      if (it_start->first != from) segments[from] = std::prev(it_start)->second;
    }

    // if (it == segments.begin() || it == segments.end() || it->first != from)
    // {
    //   int previous_value = (it == segments.begin()) ? 0 :
    //   std::prev(it)->second; segments[from] = previous_value; it =
    //   segments.find(from);  // Update iterator to new segment
    // }

    // Now handle the `to` boundary
    auto it_end = segments.lower_bound(to);
    if (it_end == segments.begin()) {
      if (segments.empty() || it_end->first != from) segments[from] = 0;
    } else if (it_end == segments.end()) {
      segments[from] = 0;
    } else if (it_end->first != from) {
      if (it_end->first != from) segments[from] = std::prev(it_end)->second;
    }

    // if (it == segments.begin() || it == segments.end() || it->first != to) {
    //   int previous_value = (it == segments.begin()) ? 0 :
    //   std::prev(it)->second; segments[to] = previous_value;
    // }

    // Apply changes to the range [from, to)
    for (auto iter = it_start; iter != it_end; ++iter) {
      if (isAdd) {
        iter->second += amount;
      } else {
        iter->second = amount;
      }
    }

    // Clean up: remove redundant entries where intensity stays the same
    for (auto iter = it_start; iter != it_end; ++iter) {
      if (iter == segments.begin()) continue;
      if (iter->second == prev(iter)->second) {
        iter = segments.erase(iter);  // Erase and advance iterator
      }
    }

    // handle edge case
    if (!segments.empty() && segments.begin()->second == 0)
      segments.erase(segments.begin());
    if (segments.size() == 1 && segments.begin()->second == 0)
      segments.erase(segments.begin());

    // auto prev = segments.begin();
    // for (auto iter = std::next(segments.begin()); iter != segments.end();) {
    //   if (iter->second == prev->second) {
    //     iter = segments.erase(iter);  // Erase and advance iterator
    //   } else {
    //     prev = iter++;
    //   }
  }
};

int main() {
  SegmentManager manager;

  // Test cases as described
  manager.printSegments();  // Start: []

  //   manager.add(10, 30, 1);   // Call: add(10, 30, 1)
  //   manager.printSegments();  // Expected: [[10,1],[30,0]]

  //   manager.add(20, 40, 1);   // Call: add(20, 40, 1)
  //   manager.printSegments();  // Expected: [[10,1],[20,2],[30,1],[40,0]]

  //   manager.add(10, 40, -2);  // Call: add(10, 40, -2)
  //   manager.printSegments();  // Expected: [[10,-1],[20,0],[30,-1],[40,0]]

  manager.add(10, 30, 1);
  manager.printSegments();
  manager.add(20, 40, 1);
  manager.printSegments();
  manager.add(10, 40, -1);
  manager.printSegments();
  manager.add(10, 40, -1);
  manager.printSegments();

  return 0;
}
