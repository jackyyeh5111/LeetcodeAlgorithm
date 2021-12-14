#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/* visit 1 */
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left >= right) return head;
    ListNode* cur = head;
    while (cur) {
      if (cur.val == left) break;
      cur = cur->next;
    }

    ListNode* left_prev = cur;

    ListNode* prev = cur;
    cur = cur->next;
    ListNode* next;

    while (cur) {
      if (cur.val == right) break;
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    left_prev->next = prev;
    prev->next = cur;

    if (left_prev == head) {
      ...
    }

    return head;
  }
};

int main(int argc, char** argv) {
  Solution sol;
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

  for (int n : sol.findDisappearedNumbers(nums)) {
    std::cout << n << ' ';
  }
  std::cout << '\n';

  //   intervals = {{1, 3}, {6, 9}};
  //   newInterval = {2, 5};
  //   for (vector<int> ans : sol.insert(intervals, newInterval)) {
  //     for (int n : ans) std::cout << n << ' ';
  //     std::cout << '\n';
  //   }
  //   std::cout << '\n';

  return 0;
}