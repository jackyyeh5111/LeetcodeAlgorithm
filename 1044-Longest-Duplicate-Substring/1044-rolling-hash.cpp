#include "../utils.hpp"

/*
  sliding window approach:
    XX[XXX]X
     XX[XXX]X

    str_len = ?

    1. bs to search the str_length of sliding window
    2. rolling hash(base 26) each sliding window and put in a set. If set has
  duplicated hash value, it means duplicated substring of str_len is found
 */
class Solution {
 public:
  string ans = "";
  string longestDupSubstring(string s) {
    int left = 1, right = s.size();
    while (left != right) {
      int middle = left + (right - left) / 2;
      if (dupSubstringExist(s, middle))
        left = middle + 1;
      else
        right = middle;
    }

    return ans;
  }

  /*
    XX[XXX]X
     XX[XXX]X

     abcd
   */
  bool dupSubstringExist(string s, int str_len) {
    unordered_set<int> set;
    long base = 26;
    long hash = 0;
    long mod = 1e5 + 7;
    long power = 1;
    for (int i = 0; i < str_len; ++i) {
      hash = (hash * base + (s[i] - 'a')) % mod;
      if (i != str_len - 1) power = (power * base) % mod;
    }
    set.insert(hash);

    for (int i = str_len; i < s.size(); ++i) {
      hash -= ((s[i - str_len] - 'a') * power) % mod;
      hash = (hash * base + (s[i] - 'a')) % mod;

      print (set);
      if (set.find(hash) != set.end()) {
        if (str_len > ans.size()) {
          cout << "i: " << i << '\n';
          cout << "str_len: " << str_len << '\n';
          cout << "s: " << s << '\n';
          cout << "hash: " << hash << '\n';
          ans = s.substr(i - str_len + 1, str_len);
          cout << "ans: " << ans << '\n';
        }
        return true;
      }

      set.insert(hash);
    }

    return false;
  }
};

int main() {
  string s = "nana";
  Solution sol;
  string ans = sol.longestDupSubstring(s);
  std::cout << "ans: " << ans << '\n';

  string s2 = "banana";
  ans = sol.longestDupSubstring(s2);
  std::cout << "ans: " << ans << '\n';

  return 0;
}
