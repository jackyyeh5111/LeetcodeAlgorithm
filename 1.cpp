#include <cmath>
#include <iostream>
#include <vector>

/* visit 1
    ref:
    https://leetcode.com/problems/two-sum/discuss/189807/c-and-c%2B%2B-solutions.-c%2B%2B-is-O(n)-time-and-just-6-lines.-Includes-c-O(n)-hashmap-solution
*/

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> umap;
    for (int i = 0; i < nums; i++) {
      if (umap.count(target - nums[i])) {
        return {i, umap[target - nums[i]]};
      }

      umap[nums[i]] = i;
    }

    return {nums.size(), nums.size()};
  }
};