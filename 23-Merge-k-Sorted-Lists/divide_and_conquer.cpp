/* Ref:
    - https://hackmd.io/D-KdsWRnQfWT7XZ8wAD7eA
    - https://www.youtube.com/watch?v=XqA8bBoEdIY
 */

/* Approach 3: divide and conquer
  time: O(nlog(k))
  space: O(1)
 */
class SolutionTest {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (!lists.size()) return nullptr;
    return merge(lists, 0, lists.size() - 1);
  }

 private:
  ListNode *merge(const vector<ListNode *> &lists, int start, int end) {
    if (start == end) return lists[start];
    int mid = start + (end - start) / 2;
    return mergeSort(merge(lists, start, mid), merge(lists, mid + 1, end));
  }

  ListNode *mergeSort(ListNode *list1, ListNode *list2) {
    ListNode dummy;
    ListNode *tail = &dummy;
    while (list1 && list2) {
      if (list1->val > list2->val) swap(list1, list2);
      tail->next = list1;
      list1 = list1->next;
      tail = tail->next;
    }

    tail->next = list1 ? list1 : list2;

    return dummy.next;
  }
};