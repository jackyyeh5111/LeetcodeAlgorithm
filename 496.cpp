#include "utils.hpp"

class Solution2 {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> next_greater_idx;
    stack<int> s;

    for (int i = 0; i < nums2.size(); i++) {
      while (!s.empty()) {
        int idx = s.top();
        if (nums2[idx] >= nums2[i]) break;
        next_greater_idx[nums2[idx]] = nums2[i];
        s.pop();
      }

      s.push(i);
    }

    while (!s.empty()) {
      next_greater_idx[nums2[s.top()]] = -1;
      s.pop();
    }

    int n = nums1.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = next_greater_idx[nums1[i]];
    }

    return ans;
  }
};

/* approach 1: stack
    - 看到這種 next great element, 就要有直覺用 stack
    - 可以想想，如果 integers in num1, nums2 are not unique，該怎麼辦？
 */
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    std::unordered_map<int, int> next_greater_idx;
    std::stack<int> stack;

    for (int i = 0; i < nums2.size(); i++) {
      while (!stack.empty()) {
        int idx = stack.top();
        if (nums2[i] > nums2[idx]) {
          // Due to integers in nums2 are all unique, we can use map.
          next_greater_idx[nums2[idx]] = nums2[i];
          stack.pop();
          continue;
        }

        break;
      }

      stack.push(i);
    }

    vector<int> ans(nums1.size(), -1);
    for (int i = 0; i < nums1.size(); i++) {
      if (next_greater_idx.count(nums1[i])) ans[i] = next_greater_idx[nums1[i]];
    }

    return ans;
  }
};

int main(int argc, char** argv) {
  vector<int> nums1 = {2, 4};
  vector<int> nums2 = {1, 2, 3, 4};
  SolutionTemp sol;
  vector<int> ans = sol.nextGreaterElement(nums1, nums2);
  print(ans);

  //   vector<int> nums2{1, 3, 2, 4};
  //   ans = sol.nextGreaterElements(nums2);
  //   print(ans);

  //   vector<int> nums3{1, 5, 3, 4, 6};
  //   ans = sol.nextGreaterElements(nums3);
  //   print(ans);

  return 0;
}