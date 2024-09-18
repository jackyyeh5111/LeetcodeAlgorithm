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
  int ptr = low;
  for (int idx = low; idx <= high - 1; idx++) {
    if (nums[idx] < pivot) {
      swap(nums[idx], nums[ptr]);
      ptr++;
    }
  }
  swap(nums[ptr], nums[high]);
  quickSort(nums, low, ptr - 1);
  quickSort(nums, ptr + 1, high);
}

int main() {
  vector<int> nums{2, 1, 5, 4, 3, 10, 3, 4, 2};
  quickSort(nums, 0, nums.size() - 1);
  print(nums);
  return 0;
}