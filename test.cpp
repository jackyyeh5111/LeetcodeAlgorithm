#include <cstdint>  // for fixed-width integers
#include <iostream>
#include <vector>
#include <numeric>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
  ListNode node(3);
  delete node.next;
  return 0;
}