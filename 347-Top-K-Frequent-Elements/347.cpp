#include "utils.hpp"

/* approach 2: bucket sort
  Time: O(n)
*/
class Solution2 {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> map;
    for (int num : nums) map[num]++;

    vector<vector<int>> bucket(nums.size());
    for (auto it = map.begin(); it != map.end(); it++) {
      bucket[it->second].push_back(it->first);
    }

    vector<int> ans;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (ans.size() >= k) break;
      ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
    }

    return ans;
  }
};

/* approach 1: Heap + unordered_map
  Time: O(nlog(n-k))
*/
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> map;
    std::priority_queue<std::pair<int, int>> pq;
    for (int num : nums) map[num]++;

    int n = map.size();
    vector<int> ans;
    for (auto it = map.begin(); it != map.end(); it++) {
      pq.push({it->second, it->first});

      if (pq.size() > n - k) {
        ans.push_back(pq.top().second);
        pq.pop();
      }
    }

    return ans;
  }
};

int main(int argc, char** argv) {
  std::vector<int> nums{1, 1, 1, 2, 2, 3};
  int k = 2;
  Solution2 sol;
  vector<int> ans = sol.topKFrequent(nums, k);
  print(ans);
  //   std::cout << "ans: " << ans << '\n';

  return 0;
}