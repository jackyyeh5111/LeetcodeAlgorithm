/* Approach 2: min heap
  time: O(nlog(k))
  space: O(k)
 */
class Solution3 {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto comp = [](ListNode *list1, ListNode *list2) {
      return list1->val > list2->val;
    };

    std::priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(
        comp);
    for (auto list : lists) {
      if (list) pq.push(list);
    }

    ListNode dummy;
    ListNode *ans = &dummy;
    while (!pq.empty()) {
      ans->next = pq.top();
      pq.pop();
      ans = ans->next;
      if (ans->next) pq.push(ans->next);
    }

    return dummy.next;
  }
};