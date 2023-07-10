/* Brute force (recursive)*/
class Solution {
 public:
  ListNode *merge(ListNode *a, ListNode *b) {
    if (!a) return b;
    if (!b) return a;
    ListNode *temp = NULL;
    if (a->val <= b->val) {
      a->next = merge(a->next, b);
      temp = a;
    } else {
      b->next = merge(a, b->next);
      temp = b;
    }
    return temp;
  }

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *ans = nullptr;
    for (ListNode *list : lists) {
      ans = merge(ans, list);
    }

    return ans;
  }
};