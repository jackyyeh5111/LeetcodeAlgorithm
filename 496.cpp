#include "utils.hpp"

/* approach 2: stack (similar to approach 1)
    but loop from the tail of the array.
 */
class Solution2 {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> stk;
    unordered_map<int, int> mp;
    for (int num : nums2) mp[num] = -1;

    // create stack
    int next_greater = INT_MIN;
    for (int i = nums2.size() - 1; i >= 0; i--) {
      int ele = nums2[i];
      while (!stk.empty()) {
        int top = stk.top();
        if (ele <= top) {
          mp[ele] = top;
          break;
        }
        stk.pop();
      }
      stk.push(ele);
    }

    vector<int> res(nums1.size());
    for (int i = 0; i < nums1.size(); i++) {
      res[i] = mp[nums1[i]];
    }

    return res;
  }
};

/* approach 1: stack
    - 看到這種 next great element, 就要有直覺用 stack
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
  SolutionTest sol;

  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};
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