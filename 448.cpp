#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/* cyclic sort */
/* visit 2 */
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int i = 0, n = nums.size();
    while (i < n) {
      if (nums[i] != nums[nums[i] - 1])
        std::swap(nums[i], nums[nums[i] - 1]);
      else
        i++;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (i + 1 != nums[i]) ans.push_back(i + 1);
    }

    return ans;
  }
};

/* cyclic sort */
/* visit 1 wrong */
// class Solution {
//  public:
//   vector<int> findDisappearedNumbers(vector<int>& nums) {
//     /* This is wrong. We should add idx only if nums[i] equals nums[nums[i] -
//     1]
//      */
//     for (int i = 0; i < nums.size(); i++) {
//       std::swap(nums[i], nums[nums[i] - 1]);
//     }

//     vector<int> ans;
//     for (int i = 0; i < nums.size(); i++) {
//       if (i + 1 != nums[i]) ans.push_back(i + 1);
//     }

//     return ans;
//   }
// };

int main(int argc, char** argv) {
  Solution sol;
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

  for (int n : sol.findDisappearedNumbers(nums)) {
    std::cout << n << ' ';
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