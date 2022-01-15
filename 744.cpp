#include "utils.hpp"

class Solutio3 {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
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

/* 其實仔細想，next_great_idx 是多出來的變數！因為結束條件為
 * left>right，所以下一個最大的 idx 一定是 left */
class Solution2 {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    int size = letters.size();
    int left = 0, right = size - 1;
    int next_great_idx;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (letters[mid] > target) {
        right = mid - 1;
        next_great_idx = mid;
      } else {
        left = mid + 1;
        next_great_idx = left;
      }
    }

    next_great_idx = next_great_idx == size ? 0 : next_great_idx;
    return letters[next_great_idx];
  }
};

/* 沒有考慮到 non-decreasing，字母有可能是重複的！ */
class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    int size = letters.size();
    int left = 0, right = size - 1;
    int next_great_idx;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (letters[mid] == target) {
        next_great_idx = mid + 1;
        break;
      } else if (letters[mid] > target) {
        right = mid - 1;
        next_great_idx = mid;
      } else {
        left = mid + 1;
        next_great_idx = left;
      }
    }

    next_great_idx = next_great_idx == size ? 0 : next_great_idx;
    return letters[next_great_idx];
  }
};

int main(int argc, char** argv) {
  vector<char> nums{'c', 'f', 'j'};
  char target;
  target = 'a';
  Solution sol;
  char ans = sol.nextGreatestLetter(nums, target);
  std::cout << "ans: " << ans << '\n';

  target = 'c';
  ans = sol.nextGreatestLetter(nums, target);
  std::cout << "ans: " << ans << '\n';

  target = 'd';
  ans = sol.nextGreatestLetter(nums, target);
  std::cout << "ans: " << ans << '\n';

  target = 'j';
  ans = sol.nextGreatestLetter(nums, target);
  std::cout << "ans: " << ans << '\n';

  return 0;
}