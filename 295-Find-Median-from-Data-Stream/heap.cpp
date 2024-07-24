#include "utils.hpp"

/* 
  Visit 3: more elegant
 */
class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push(num);
        
        // balance
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        // swap top?
        if(!min_heap.empty() && max_heap.top() > min_heap.top()) {
            int tmp = max_heap.top();
            max_heap.pop();
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(tmp);
        }
    }
    
    double findMedian() {
        int num_element = max_heap.size() + min_heap.size();
        return num_element % 2 ? max_heap.top() : (max_heap.top() + min_heap.top() ) / 2.0;
    }
};

/**
    addNum: 1 2 3 4

    tmp: 3
    max_heap: 1 2
    min_heap: 3 4
    
    min_heap.size() <= max_heap.size() <= min_heap.size() + 1
 */

/* 
    Visit 2: More simplified code

    2 3 4
    2 3 

    L   S
    1.  1

    S.size() + 1 >= L.size() >= S.size()
    balanced!
 */

class MedianFinder {
public:
    MedianFinder() {}
    
    void addNum(int num) {
      if (!max_heap.empty() && num > max_heap.top())
        min_heap.push(num);
      else 
        max_heap.push(num);

      // check
      if (max_heap.size() < min_heap.size()) 
      {
        max_heap.push(min_heap.top());
        min_heap.pop();
      }
      if (max_heap.size() > min_heap.size() + 1) 
      {
        min_heap.push(max_heap.top());
        max_heap.pop();
      }
    }
    
    double findMedian() {
      int num_ele = max_heap.size() + min_heap.size();
      if (num_ele % 2)
        return max_heap.top();
      return (max_heap.top() + min_heap.top()) / 2.0;
    }
  private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
};

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