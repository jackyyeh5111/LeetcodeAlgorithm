#include "../utils.hpp"

/*
  ref: https://hackmd.io/xdj-7JsgTUuE9d3yRKqTXg

  p
  1 2 5 4 3
  l       h

  [smaller than p] p [larger than or equal to p]

   Take the last element as the pivot
   Top-down approach. (in-place)
 */
void quickSort(vector<int> &nums, int low, int high) {
  if (low >= high) return;
  int pivot = nums[high];
  int pi_idx = low;
  for (int i = low; i <= high - 1; i++) {
    if (nums[i] < pivot) {
      swap(nums[i], nums[pi_idx]);
      pi_idx++;
    }
  }

  swap(nums[high], nums[pi_idx]);

  quickSort(nums, low, pi_idx - 1);
  quickSort(nums, pi_idx + 1, high);
}

int main() {
  vector<int> nums{2, 1, 5, 4, 3};
  quickSortTest(nums, 0, 4);
  print(nums);
  return 0;
}