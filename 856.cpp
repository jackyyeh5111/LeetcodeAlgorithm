#include "utils.hpp"

/* ref:
    https://leetcode.com/problems/score-of-parentheses/discuss/141777/C++JavaPython-O(1)-Space
 */

/* approach 3: 
    直接用 number of layers，太神了吧！ 
    ref:
    https://hackmd.io/B5VUP8ZJQlGbW4VeJDSPwg
    
    Time: O(n)
    Space: O(1)
*/

class Solution3 {
 public:
  int scoreOfParentheses(string S) {
    int res = 0, l = 0;
    for (int i = 0; i < S.length(); ++i) {
      if (S[i] == '(')
        l++;
      else
        l--;
      if (S[i] == ')' && S[i - 1] == '(') res += 1 << l;
    }
    return res;
  }
};

/* approach 2: array 來充當 stack */
class Solution2 {
 public:
  int scoreOfParentheses(string S) {}
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
  std::string s = "(()(()()))";
  Solution3 sol;
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