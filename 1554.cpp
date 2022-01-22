#include "utils.hpp"

/*
    ref:
    https://www.youtube.com/watch?v=2aYIO0MR_F4
 */

/*
    Approach: rolling hash
    Time: O(m * n)

    abcd -> abc!
    acbd -> acb!
    aacd -> aac!

    1. subtract hash
    2. add into set
    3. compare
*/
typedef uint64_t ULL;
class Solution {
 public:
  bool differByOne(vector<string>& dict) {
    int base = 26;
    int n = dict.size();
    int m = dict[0].size();
    vector<ULL> hashs(n);

    // create rolling hash table.
    for (int i = 0; i < n; i++) {
      ULL h = 0;

      /* 很容易理解，如果十進位 base 就是 10，往左一位就是 * base */
      for (auto ch : dict[i]) h = h * base + (ch - 'a');
      hashs[i] = h;
    }

    ULL power = 1;
    for (int j = m - 1; j >= 0; j--) {
      unordered_set<ULL> set;
      for (int i = 0; i < n; i++) {
        ULL new_hash = hashs[i] - power * (dict[i][j] - 'a');
        if (set.find(new_hash) != set.end()) return true;
        set.insert(new_hash);
      }

      power *= base;
    }

    return false;
  }
};

int main() {
  vector<std::string> nums1{"abcd", "acbd", "aacd"};
  Solution sol;
  bool ans = sol.differByOne(nums1);
  std::cout << "ans: " << ans << '\n';

  vector<std::string> nums2{"abcd", "acbd", "aace"};
  ans = sol.differByOne(nums2);
  std::cout << "ans: " << ans << '\n';

  return 0;
}
