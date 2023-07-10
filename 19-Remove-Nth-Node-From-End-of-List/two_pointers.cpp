/**
 * More elegant code.
 */
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy;
    ListNode* ptr = &dummy;
    ptr->next = head;
    ListNode *left = ptr, *right = ptr;
    for (int i = 0; i <= n; ++i) right = right->next;
    while (right) {
      left = left->next;
      right = right->next;
    }
    left->next = left->next->next;
    return ptr->next;
  }
};

/*
    D 1 2 3 4 5
            l
                r

    D 1
    l
        r
    D 1 2
      l
          r
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy;
    dummy.next = head;
    ListNode *ptr = &dummy, *tail = &dummy;
    int cnt = 0;
    while (tail) {  // n = 2, cnt = 5
      tail = tail->next;
      ++cnt;
      if (cnt > n + 1) {
        ptr = ptr->next;
      }
    }

    // remove node
    if (ptr->next == head) return head->next;
    if (n == 1)
      ptr->next = nullptr;
    else
      ptr->next = ptr->next->next;

    return head;
  }
};

/*
     d -> 1

     d -> 1 -> 2 // cnt = 2, n = 1
          ^    ^
         ptr tail

     d -> 1 -> 2 -> 3 -> 4 -> 5
     ^         ^
     ptr      tail
 */