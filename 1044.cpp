#include "utils.hpp"

class Solution {
 public:
  string longestDupSubstring(string s) {
      
  }
};

int main() {
  string s = "banana";
  Solution sol;
  string ans = sol.longestDupSubstring(s);
  std::cout << "ans: " << ans << '\n';

  string s2 = "abcd";
  ans = sol.longestDupSubstring(s2);
  std::cout << "ans: " << ans << '\n';

  return 0;
}
