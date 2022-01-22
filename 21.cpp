#include "utils.hpp"

using namespace std;

/* ref:
    - https://hackmd.io/D-KdsWRnQfWT7XZ8wAD7eA
    - https://www.youtube.com/watch?v=qckKEYP9bBA
 */

/* Brute force (iterative)
    Time: O(n^2)
*/
class Solution2 {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy;
    ListNode* tail = &dummy;

    while (list1 and list2) {
      if (list1->val <= list2->val) {
        tail->next = list1;
        list1 = list1->next;
      } else {
        tail->next = list2;
        list2 = list2->next;
      }

      tail = tail->next;
    }

    if (!list1)
      tail->next = list2;
    else
      tail->next = list1;

    return dummy.next;
  }
};

/* Brute force (recursive) */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->val <= list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoLists(list1, list2->next);
      return list2;
    }
  }
};

/* Brute force (recursive)
    可以不需要 dummy，更簡潔的寫法
*/
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    ListNode dummy;
    ListNode* tail = &dummy;

    if (list1->val <= list2->val) {
      tail->next = list1;
      tail->next->next = mergeTwoLists(list1->next, list2);
    } else {
      tail->next = list2;
      tail->next->next = mergeTwoLists(list1, list2->next);
    }

    return tail->next;
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