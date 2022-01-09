#include "utils.hpp"

/* Visit 1
ref:
https://leetcode.com/problems/find-median-from-data-stream/discuss/1048192/C%2B%2B-Easy-Understandable-Two-heaps-Intuitive-Solution.-O(logn)-add-O(1)-find
*/

class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    if (max_heap.empty() or num < max_heap.top())
      max_heap.push(num);
    else
      min_heap.push(num);

    if (min_heap.size() > max_heap.size() + 1) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    } else if (max_heap.size() > min_heap.size() + 1) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    }
  }

  double findMedian() {
    // even item
    if (min_heap.size() == max_heap.size()) {
      if (max_heap.empty())
        return 0;
      else
        return (min_heap.top() + max_heap.top()) / 2.0;
    } else {
      return min_heap.size() > max_heap.size() ? min_heap.top()
                                               : max_heap.top();
    }
  }

 private:
  std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
  std::priority_queue<int, std::vector<int> > max_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(int argc, char **argv) {
  MedianFinder medianFinder = MedianFinder();
  medianFinder.addNum(1);  // arr = [1]
  medianFinder.addNum(2);  // arr = [1, 2]
  std::cout << medianFinder.findMedian()
            << '\n';       // return 1.5 (i.e., (1 + 2) / 2)
  medianFinder.addNum(3);  // arr[1, 2, 3]
  std::cout << medianFinder.findMedian() << '\n';  // return 2.0

  return 0;
}