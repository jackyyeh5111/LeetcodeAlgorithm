#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/* 
    1. sort
    2. for loop with base pointer. for each iteration, use two pointers pointing to elements.
       When moving pointers, make sure cur element is not the same as the previous one

    [-1 0 1]
    -1 0 0 1 1 2
           l  
     b
         r
 
    more elegant code.
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int base = 0;
        vector<vector<int> > ans;
        for (int base=0; base < nums.size(); base++) {
            if (nums[base] > 0) break; // early stop
            if (base != 0 && nums[base] == nums[base - 1]) continue;
            twoSum(nums, base, ans);
        }
        return ans;
    }
    void twoSum(const vector<int> &nums, int base, vector<vector<int>> &ans) {
        int left = base + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right] + nums[base];
            if (sum > 0) right--;
            else if (sum < 0) left++;
            else {
                ans.push_back({nums[base], nums[left], nums[right]});
                left++;
                right--;
                while(left < right && nums[left] == nums[left-1])
                    left++;
            }
        }
    }

};

/* 
  Ref: https://www.youtube.com/watch?v=9nG3tEJ6-8k&t=3s

  Note:
    Much simpler than hashmap approach. 
 */
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    if (n < 3) return ans;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) return ans;
      int left = i + 1;
      int right = n - 1;

      // item we have seen. skip.
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum < 0)
          left++;
        else if (sum > 0)
          right--;
        else {
          ans.push_back({nums[i], nums[left], nums[right]});
          left++;
          right--;

          while (left < right && nums[left] == nums[left - 1]) left++;
          while (left < right && nums[right] == nums[right + 1]) right--;
        }
      }
    }

    return ans;
  }
};

int main(int argc, char** argv) {
  Solution sol;
  std::vector<int> nums{-1, 0, 1, 2, -1, -4};
  //   std::cout << sol.removeDuplicates(nums) << '\n';
  for (vector<int> ans : sol.threeSum(nums)) {
    for (int n : ans) std::cout << n << ' ';
    std::cout << '\n';
  }
  std::cout << '\n';

  //   nums = {1};
  //   std::cout << sol.maxSubArray(nums) << '\n';
  return 0;
}