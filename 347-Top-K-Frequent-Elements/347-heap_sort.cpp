#include "../utils.hpp"

/* approach 1: Heap + unordered_map
  Time: O(nlog(n-k))
*/
class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
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

int main(int argc, char **argv) {
  std::vector<int> nums{1, 1, 1, 2, 2, 3};
  int k = 2;
  SolutionTest sol;
  vector<int> ans = sol.topKFrequent(nums, k);
  print(ans);
  //   std::cout << "ans: " << ans << '\n';

  return 0;
}