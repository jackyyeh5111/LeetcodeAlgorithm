#include "../utils.hpp"

/*
    No duplicates
 */

void setFunc() {
  set<int> myset;
  myset.insert(3);
  myset.insert(5);
  myset.insert(7);  // {3, 5, 7}, O(log(n))

  set<int>::iterator it;
  it = myset.find(7);  // O(log(n)), it points to 7.

  pair<set<int>::iterator, bool> ret;
  ret = myset.insert(3);  // no new element is inserted
  if (ret.second == false) {
    it = ret.first;  // now point to 3
  }
  std::cout << "it points to: " << *it << '\n';

  myset.insert(it, 9);  // Given set a hint! May let it insert more quickly.
                        // Maybe O(log(n)) => O(1)

  myset.erase(it);
  myset.erase(3);  // None of sequential containers provide this kind of erase.

  // This is not allowed. Dereference of iterator of associative containers is
  // a const value.
  // *it = 5;
}

int main() {
  setFunc();
  unordered_map<int, string> um;
  cout << "um: " << um.at(0) << '\n';
  return 0;
}