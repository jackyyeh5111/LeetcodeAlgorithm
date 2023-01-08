#include "utils.hpp"

/* Instead of loop */
class Solution3 {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> stk;
    int n = nums.size();
    vector<int> res(n, -1);

    for (int i = 0; i < n * 2; i++) {
      int ele = nums[i];
      while (!stk.empty()) {
        int top_idx = stk.top();
        if (ele > nums[top_idx % n]) {
          if (top_idx < n) res[top_idx] = ele;
          stk.pop();
          continue;
        }

        break;
      }
      stk.push(i);
    }

    return res;
  }
};

/* Much more elegant than approach 1 */
class Solution2 {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> stk;
    helper(ans, stk, nums);
    helper(ans, stk, nums);

    return ans;
  }

  void helper(vector<int>& ans, stack<int>& stk, const vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      while (!stk.empty()) {
        int top_idx = stk.top();
        if (nums[top_idx] >= nums[i]) break;
        ans[top_idx] = nums[i];
        stk.pop();
      }

      stk.push(i);
    }
  }
};

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
  Solution3 sol;
  vector<int> nums{1, 2, 1};
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