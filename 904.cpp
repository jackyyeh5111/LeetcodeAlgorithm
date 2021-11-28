#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

/*
    ref:
    https://leetcode.com/problems/fruit-into-baskets/discuss/674800/C%2B%2B-2-solutions
 */

using namespace std;

class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    unordered_map<int, int> um;
    int r = 0;
    int l = 0;
    int cnt = 0;
    int ans = 0;

    while (r < n) {
      if (um[fruits[r]] == 0) cnt++;
      um[fruits[r]]++;
      r++;

      while (l < r && cnt > 2) {
        um[fruits[l]]--;
        if (um[fruits[l]] == 0) cnt--;
        l++;
      }

      ans = max(ans, r - l);
    }

    return ans;
  }
};

int main(int argc, char** argv) {
  Solution sol;

  std::vector<int> nums{1, 2, 1};
  std::cout << sol.totalFruit(nums) << '\n';

  nums = {0, 1, 2, 2};
  std::cout << sol.totalFruit(nums) << '\n';

  nums = {1, 2, 3, 2, 2};
  std::cout << sol.totalFruit(nums) << '\n';

  nums = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  std::cout << sol.totalFruit(nums) << '\n';

  return 0;
}