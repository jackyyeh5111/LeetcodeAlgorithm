#include "utils.hpp"

/* 
  Solution with mod

    clarification:
    1. [abc, abc] -> not the case. dict[i] should be unique
    2. dict[i].size() == dict[j].size()
    
    abc -> 100
    abd -> 101
    aef -> 123

    abc -> 1 * 26^2 + 2 * 26^1 + 3
 */
class Solution2 {
public:
    bool differByOne(vector<string>& dict) {
        if (dict.size() < 2)
            return false;
        
        // construct hashs
        vector<long long> hashs;
        long long BASE = 26;
        long long mod = 1e9 + 7;
        for (string word : dict) {
            long long hash = 0;
            for (char ch : word)
                hash = ((hash * BASE) % mod + (ch - 'a')) % mod;
            hashs.push_back(hash);
        }

        // compare if collision happens
        long long power = 1;
        for (int mask_pos = dict[0].size() - 1; mask_pos >= 0 ; mask_pos--) {
            unordered_set<long long> vals;
            for (int i = 0; i < dict.size(); i++) {
                long long mask_hash = (hashs[i] - ((dict[i][mask_pos] - 'a') * power) % mod) % mod;
                if (vals.count(mask_hash))
                    return true;
                vals.insert(mask_hash);
            }
            power = (power * BASE) % mod;
        }
        return false;
    }
};

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
