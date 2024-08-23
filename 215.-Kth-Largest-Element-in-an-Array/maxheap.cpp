#include "utils.hpp"

/* Visit 1
    c++ priority default 就是 max heap.
*/
class Solution {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    std::priority_queue<int> pq;
    for (int num : nums) {
      pq.push(num);
    }

    for (int i = 0; i < k - 1; i++) pq.pop();

    return pq.top();
  }
};

int main(int argc, char **argv) {
  vector<int> nums{3, 2, 1, 5, 6, 4};
  int k = 2;
  Solution sol;
  int ans = sol.findKthLargest(nums, k);
  std::cout << "ans: " << ans << '\n';

  return 0;
}