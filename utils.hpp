#include <limits.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/*
    initTreeNodes usage:
    int main(int argc, char **argv) {
        vector<TreeNode *> vals{new TreeNode(3), new TreeNode(9), new
   TreeNode(20), nullptr,         nullptr,         new TreeNode(15), new
   TreeNode(7)}; TreeNode *root = initTreeNodes(vals);

        Solution2 sol;
        vector<vector<int>> ans = sol.levelOrderBottom(root);
        print(ans);

        return 0;
    }
 */
TreeNode *initTreeNodes(vector<TreeNode *> nodes) {
  // assign child to each nodes
  int len = nodes.size();
  for (int i = 0; i < len; i++) {
    if (!nodes[i]) continue;

    int left_child_idx = 2 * i + 1;
    int right_child_idx = 2 * i + 2;
    if (left_child_idx < len) nodes[i]->left = nodes[left_child_idx];
    if (right_child_idx < len) nodes[i]->right = nodes[right_child_idx];
  }

  return nodes[0];
}

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *initListNode(const vector<int> &nums) {
  vector<ListNode *> nodes;
  for (int num : nums) {
    nodes.push_back(new ListNode(num));
  }

  for (int i = 0; i < nodes.size() - 1; i++) {
    nodes[i]->next = nodes[i + 1];
  }
  return nodes[0];
}

template <typename T>
void print(vector<vector<T>> &vecs) {
  for (vector<T> vec : vecs) {
    for (auto val : vec) std::cout << val << ' ';
    std::cout << '\n';
  }
}

template <typename T>
void print(vector<T> &vecs) {
  for (auto val : vecs) std::cout << val << ' ';
  std::cout << '\n';
}

template <typename T>
void print(list<T> &mylist) {
  for (auto val : mylist) std::cout << val << ' ';
  std::cout << '\n';
}

void print(ListNode *list) {
  ListNode *head = list;
  while (head) {
    std::cout << head->val << ' ';
    head = head->next;
  }
  std::cout << '\n';
}

template <typename T>
void print(stack<T> stk) {
  while (!stk.empty()) {
    std::cout << stk.top() << ' ';
    stk.pop();
  }
  std::cout << '\n';
}

template <typename T>
void print(unordered_set<T> set) {
  for (auto itr : set) {
    cout << itr << " ";
  }
  std::cout << '\n';
}