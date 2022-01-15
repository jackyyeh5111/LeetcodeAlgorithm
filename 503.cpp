#include "utils.hpp"

/*
    ref:
   https://leetcode.com/problems/next-greater-element-ii/discuss/98270/JavaC%2B%2BPython-Loop-Twice
 */

/* approach 1 (revised): stack
    - 幹嘛又存 num 又存 idx? 有 idx 就可以找到 num 啊！
    - 另外，如果找不到就要 assign -1, 那 ans 一開始就 initialzie -1 就好！
    - 不用多一個 for loop
    - 以後看到 circular 要有直覺可以用 modulo operator
 */
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {

  }
};

/* approach 1: stack
    看到這種 next great element, 就要有直覺用 stack
 */
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int size = nums.size();
    std::stack<int> num_stack;
    std::stack<int> idx_stack;
    vector<int> ans(size, 0);
    for (int i = 0; i < size; i++) {
      while (!num_stack.empty()) {
        if (nums[i] > num_stack.top()) {
          ans[idx_stack.top()] = nums[i];
          num_stack.pop();
          idx_stack.pop();
          continue;
        }

        break;
      }

      num_stack.push(nums[i]);
      idx_stack.push(i);
    }

    // check circular
    for (int i = 0; i < size; i++) {
      while (!num_stack.empty()) {
        if (nums[i] > num_stack.top()) {
          ans[idx_stack.top()] = nums[i];
          num_stack.pop();
          idx_stack.pop();
          continue;
        }

        break;
      }

      if (num_stack.empty()) break;
    }

    while (!idx_stack.empty()) {
      ans[idx_stack.top()] = -1;
      idx_stack.pop();
    }

    return ans;
  }
};

int main(int argc, char** argv) {
  vector<int> nums{1, 2, 1};
  Solution sol;
  vector<int> ans = sol.nextGreaterElements(nums);
  print(ans);

  vector<int> nums2{1, 3, 2, 4};
  ans = sol.nextGreaterElements(nums2);
  print(ans);

  vector<int> nums3{1, 5, 3, 4, 6};
  ans = sol.nextGreaterElements(nums3);
  print(ans);

  return 0;
}