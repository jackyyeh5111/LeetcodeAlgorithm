#include "utils.hpp"

/*
ref:
  https://hackmd.io/1_UvvM01T6W6R2cCbMGYdg
 */

/*
  Example 1:

  Input: s = "()"
  Output: 1
  Example 2:

  Input: s = "(())"
  Output: 2
  Example 3:

  Input: s = "()()"
  Output: 2

  Input: s = "(()())"
  Output: 4

  Input: s = "()(())"
  Output: 4
 */
class Solution3 {
 public:
  int scoreOfParentheses(string s) {
    stack<int> stk;
    int cur = 0;
    for (char ch : s) {
      if (ch == '(') {
        stk.push(cur);
        cur = 0;
      } else {  // ch == ')'
        if (cur == 0)
          cur = 1;
        else
          cur *= 2;
        cur += stk.top();
        stk.pop();
      }
    }

    return cur;
  }
};

/* ref:
    https://leetcode.com/problems/score-of-parentheses/discuss/141777/C++JavaPython-O(1)-Space
 */

/* approach 3:
    直接用 number of layers，太神了吧！

    Time: O(n)
    Space: O(1)
*/

class Solution2 {
 public:
  int scoreOfParentheses(string S) {
    int l = 0, ans = 0;
    int n = S.size();
    for (int i = 0; i < n; i++) {
      if (S[i] == '(') l++;
      if (S[i] == ')') l--;
      if (S[i] == ')' && S[i - 1] == '(') ans += (1 << l);
    }

    return ans;
  }
};

/* approach 1: stack
    - 看到 paraentheses, 就要有直覺用 stack
 */
class Solution {
 public:
  int scoreOfParentheses(string S) {
    std::stack<int> stack;
    int cur = 0;
    for (char i : S) {
      if (i == '(') {
        stack.push(cur);
        cur = 0;
      } else {
        cur = stack.top() + std::max(cur * 2, 1);
        stack.pop();
      }
    }

    return cur;
  }
};

int main(int argc, char** argv) {
  std::string s = "()()";
  Solution2 sol;
  int ans = sol.scoreOfParentheses(s);
  std::cout << "ans: " << ans << '\n';

  //   vector<int> nums2{1, 3, 2, 4};
  //   ans = sol.nextGreaterElements(nums2);
  //   print(ans);

  //   vector<int> nums3{1, 5, 3, 4, 6};
  //   ans = sol.nextGreaterElements(nums3);
  //   print(ans);

  return 0;
}