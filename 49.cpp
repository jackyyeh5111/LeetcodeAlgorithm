#include "utils.hpp"

/*
    用 string(size = 26，每個 index 對應到一個字元的出現數量) 當作 hash key
    有可能同一個 char 次數超過 9，就根據 ascii code 給
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        for (string str : strs) {
            string key(26, '0');
            for (char ch : str)
                key[ch - 'a']++;
            dict[key].push_back(str);
        }
        
        vector<vector<string>> ans;
        for (auto pair : dict) 
            ans.push_back(pair.second);
        return ans;
    }
};

/*
    用 bitmap 當作 hash key

    fail:
    沒有考慮到 character 重複的情況！
 */
class Solution2 {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<int, vector<string>> hash;
    for (string str : strs) {
      int bit_mask = 0;
      for (char ch : str) {
        bit_mask += (1 << (ch - 'a'));
      }

      if (hash.find(bit_mask) == hash.end())
        hash[bit_mask] = vector<string>{str};
      else
        hash[bit_mask].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto pair : hash) {
      ans.push_back(pair.second);
    }

    return ans;
  }
};

/*
    Prime number List (first 26):
    2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 73 79 83 89 97 101 103
    a b c d e  ..

    eat ==> 11 + 2 + ..
    tea

    完全錯啊..
    fail case: [["ac","d"]]
 */

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<char, int> hash;
    vector<int> primes{2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37,  41,
                       43, 47, 53, 59, 61, 67, 73, 79, 83, 89, 97, 101, 103};
    for (int i = 0; i < 26; i++) {
      hash['a' + i] = primes[i];
    }

    int n = strs.size();
    vector<int> hash_nums(n);
    for (int i = 0; i < n; i++) {
      int hash_num = 0;
      for (char ch : strs[i]) {
        hash_num += hash[ch];
      }

      hash_nums[i] = hash_num;
    }

    unordered_map<int, vector<string>> ans;
    for (int i = 0; i < n; i++) {
      int hash_num = hash_nums[i];
      if (ans.find(hash_num) == ans.end())
        ans[hash_num] = vector<string>{strs[i]};
      else
        ans[hash_num].push_back(strs[i]);
    }

    vector<vector<string>> res;
    for (auto pair : ans) res.push_back(pair.second);

    return res;
  }
};

int main() {
  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution3 sol;
  auto ans = sol.groupAnagrams(strs);
  print(ans);
  return 0;
}