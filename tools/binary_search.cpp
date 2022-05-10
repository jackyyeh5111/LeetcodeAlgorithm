
/* Modify from 744.cpp */
class Solution {
 public:
  char binarySearch(vector<char> &letters, char target) {
    int size = letters.size();
    int left = 0, right = size - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (letters[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    int next_great_idx = left == size ? 0 : left;
    return letters[next_great_idx];
  }
};