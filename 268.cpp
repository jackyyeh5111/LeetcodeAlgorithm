#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/* XOR */
/* visit 1 */
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int x1 = 0, x2 = 0;
    for (int i = 0; i < nums.size(); i++) {
      x1 = x1 ^ nums[i];
      x2 = x2 ^ (i + 1);
    }

    return x1 ^ x2;
  }
};

int main(int argc, char** argv) {
  Solution sol;
  vector<vector<int>> firstList = {{1, 7}};
  vector<vector<int>> secondList = {{3, 10}};
  for (vector<int> ans : sol.intervalIntersection(firstList, secondList)) {
    for (int n : ans) std::cout << n << ' ';
    std::cout << '\n';
  }
  std::cout << '\n';

  //   intervals = {{1, 3}, {6, 9}};
  //   newInterval = {2, 5};
  //   for (vector<int> ans : sol.insert(intervals, newInterval)) {
  //     for (int n : ans) std::cout << n << ' ';
  //     std::cout << '\n';
  //   }
  //   std::cout << '\n';

  return 0;
}