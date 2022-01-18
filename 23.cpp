#include "utils.hpp"

using namespace std;

/* Ref:
    https://leetcode.com/problems/merge-k-sorted-lists/discuss/1032551/C%2B%2B-or3-sols-or-Brute-force-or-Priority-queue-or-Divide-and-Conquer-method
 */

/* Brute force (recursive)*/

// [[1,4,5],[1,3,4],[2,6]]

// 1->4->5 2->3

class Solution {
 public:
  ListNode* merge(ListNode* a, ListNode* b) {
    if (!a) return b;
    if (!b) return a;

    ListNode* tmp = nullptr;
    if (a->val >= b->val) {
      a->next = merge(a->next, b);
      tmp = a;
    } else {
      b->next = merge(a, b->next);
      tmp = b;
    }

    return tmp;
  }

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* ans = nullptr;
    for (ListNode* list : lists) {
      ans = merge(ans, list);
    }

    return ans;
  }
};

int main(int argc, char** argv) {
  vector<vector<int>> Solution sol;
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