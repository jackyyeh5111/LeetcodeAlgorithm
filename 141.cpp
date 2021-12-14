#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


/* Ref:
    https://hackmd.io/qX6k3iZ9SP6GoqeBS6hxrA
 */
/* Visit 1 */
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (!head) return false;

    ListNode *slow = head, *fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
  }
};

int main(int argc, char **argv) {
  Solution sol;
  std::vector<int> nums{-1, 0, 1, 2, -1, -4};
  //   std::cout << sol.removeDuplicates(nums) << '\n';
  for (vector<int> ans : sol.threeSum(nums)) {
    for (int n : ans) std::cout << n << ' ';
    std::cout << '\n';
  }
  std::cout << '\n';

  //   nums = {1};
  //   std::cout << sol.maxSubArray(nums) << '\n';
  return 0;
}