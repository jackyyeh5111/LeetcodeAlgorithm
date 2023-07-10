#include "utils.hpp"

/*
    ref:
    https://www.youtube.com/watch?v=2aYIO0MR_F4

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
    // init hashs
    vector<ULL> hashs;
    ULL base = 26;
    int N = dict.size();
    int M = dict[0].size();
    for (auto str : dict) {
      ULL hash = 0;
      for (int i = 0; i < M; ++i) {
        hash = hash * base + (str[i] - 'a');
      }
      hashs.push_back(hash);
    }

    // remove each individual character
    ULL power = 1;
    for (int j = M - 1; j >= 0; --j) {
      unordered_set<ULL> us;
      for (int i = 0; i < N; ++i) {
        ULL hash = hashs[i] - power * (dict[i][j] - 'a');
        if (us.find(hash) != us.end()) return true;
        us.insert(hash);
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
