#include "utils.hpp"

using namespace std;

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

/*
  lists = [[1,4,5],[1,3,4],[2,6]]
 */
class SolutionTest {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
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
      if (list1->val < list2->val) {
        tail->next = list1;
        list1 = list1->next;
      } else {
        tail->next = list2;
        list2 = list2->next;
      }

      tail = tail->next;
    }

    tail->next = list1 ? list1 : list2;

    return dummy.next;
  }
};

int main(int argc, char **argv) {
  vector<ListNode *> lists{initListNode({1, 4, 5}), initListNode({1, 3, 4}),
                           initListNode({2, 6})};
  SolutionTest sol;
  ListNode *ans = sol.mergeKLists(lists);
  print(ans);
  return 0;
}