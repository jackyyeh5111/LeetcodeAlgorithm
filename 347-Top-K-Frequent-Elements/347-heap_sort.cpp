#include "../utils.hpp"

/* approach 1: Heap + unordered_map
  Time: O(nlog(n-k))
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int num : nums) counter[num]++;

        // init max_heap
        priority_queue<pair<int, int>> max_heap;
        for (const auto& [num, freq] : counter) {
            max_heap.emplace(freq, num);
        }

        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            auto [freq, num] = max_heap.top();
            max_heap.pop();
            ans[i] = num;
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