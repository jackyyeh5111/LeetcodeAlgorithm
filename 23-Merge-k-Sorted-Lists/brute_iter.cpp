/* Brute force (iterative)
    Time: O(n^2)
*/
class Solution2 {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *ans = nullptr;
    for (ListNode *list : lists) {
      ListNode *tmp = new ListNode();
      ListNode *tmp2 = tmp;
      while (ans && list) {
        if (ans->val <= list->val) {
          tmp2->next = ans;
          ans = ans->next;
        } else {
          tmp2->next = list;
          list = list->next;
        }

        tmp2 = tmp2->next;
      }

      if (!ans) tmp2->next = list;
      if (!list) tmp2->next = ans;

      ans = tmp->next;
      delete tmp;
    }

    return ans;
  }
};