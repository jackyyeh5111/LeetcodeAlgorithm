#include <vector>

/*
    This binary Search can serve as lower_bound or upper_bound by providing
   parameter "is_upper_bound".
 */
int binarySearch(const vector<int>& vec, int target, bool is_upper_bound) {
  int left = 0;
  int right = vec.size();  // notice here, not vec.size() - 1 !!!

  /*
      tgt = 5
      1 3
          l
          r
        m
   */
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (vec[mid] == target)
      return is_upper_bound ? mid + 1 : mid;
    else if (vec[mid] < target)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

template <typename Iterator, typename T>
Iterator lower_bound_jacky(Iterator first, Iterator last, const T& target) {
  while (first < last) {
    Iterator mid = first + (last - first) / 2;

    // If mid is less than the target, narrow search to the right half
    if (*mid < target)
      first = mid + 1;
    else
      last = mid;  // Otherwise, narrow search to include mid or the left half
  }
  return first;  // Returns the first element not less than the target
}

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 3, 5, 7, 9};
  int target = 10;

  auto it = lower_bound_jacky(vec.begin(), vec.end(), target);

  if (it != vec.end()) {
    std::cout << "Lower bound of " << target
              << " is at position: " << (it - vec.begin()) << "\n";
    std::cout << "Element: " << *it << "\n";
  } else {
    std::cout << "Element not found\n";
  }
  return 0;
}
