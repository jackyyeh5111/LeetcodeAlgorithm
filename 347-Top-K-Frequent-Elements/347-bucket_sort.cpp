#include "../utils.hpp"

/* approach 2: concept of bucket sort (not actually do sorting operations)
  Time: O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      // bucket sort
      int N = nums.size();
      vector<vector<int>> buckets(N + 1);

      unordered_map<int, int> freqs; // num -> freq
      for (int num : nums)
        freqs[num]++;
      
      for (auto pair : freqs) {
        buckets[pair.second].push_back(pair.first);
      }

      vector<int> ans;
      for (int i = N; i >= 0; i--) {
        ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        if (ans.size() == k)
          break;
      }
      return ans;
    }
};