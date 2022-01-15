// deque::begin
#include <deque>
#include <iostream>

int main() {
  std::deque<int> mydeque;

  for (int i = 1; i <= 5; i++) mydeque.push_back(i);

  std::cout << "mydeque contains:";

  for (std::deque<int>::iterator it = mydeque.begin(); it != mydeque.end();
       it++) {
    std::cout << ' ' << *it;
  }

  std::cout << '\n';

  while (!mydeque.empty()) {
    std::cout << ' ' << mydeque.front();
    mydeque.pop_front();
  }

  std::cout << '\n';

  return 0;
}