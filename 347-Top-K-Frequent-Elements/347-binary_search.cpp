#include "../utils.hpp"

/*
    Time complexity: O(nlog(C))
    C: Possibile number of frequency

    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
 */
class Solution {
 public:
  unordered_map<int, int> um;
  vector<int> topKFrequent(vector<int>& nums, int k) {
    for (auto num : nums) um[num]++;

    int left = 0, right = nums.size();
    while (left < right) {
      //   int freq = (left + right) / 2;
      int freq = right - (right - left) / 2;
      if (countFreqGreaterOrEqual(freq) >= k) {
        left = freq; // 特別注意，不行 left = freq + 1; 因為 freq 仍然有可能是答案
      } else {
        right = freq - 1;
      }
    }

    int freq = left;
    vector<int> res;
    for (auto pair : um) {
      if (pair.second >= freq) res.push_back(pair.first);
    }

    return res;
  }

  int countFreqGreaterOrEqual(int freq) {
    int res = 0;
    for (auto pair : um) {
      if (pair.second >= freq) res++;
    }

    return res;
  }
};