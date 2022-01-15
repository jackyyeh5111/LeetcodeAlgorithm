#include "utils.hpp"

/* ref:
    https://leetcode.com/problems/online-stock-span/discuss/168311/C++JavaPython-O(1)
 */

/* approach 2: stack
 */
class StockSpanner {
 public:
  std::pair<int, int> history;

  StockSpanner() {}

  int next(int price) {

  }
};

/* approach 1:
    用兩個 vector 來存。
    但如果要回溯歷史的話，其實用最新的 element
   包含過往資訊即可，歷史不重要的資訊都可以 pop
 */
class StockSpanner {
 public:
  std::vector<int> history_price;
  std::vector<int> history;
  StockSpanner() {}

  int next(int price) {
    int size = history.size();
    int check_idx = size - 1;
    if (size) {
      while (check_idx >= 0) {
        if (price < history_price[check_idx]) break;
        check_idx -= history[check_idx];
      }
    }

    int num_greater_or_equal = size - check_idx;
    history_price.push_back(price);
    history.push_back(num_greater_or_equal);

    return num_greater_or_equal;
  }
};

int main(int argc, char** argv) {
  StockSpanner* stockSpanner = new StockSpanner();
  std::cout << stockSpanner->next(100) << '\n';  // return 1
  std::cout << stockSpanner->next(80) << '\n';   // return 1
  std::cout << stockSpanner->next(60) << '\n';   // return 1
  std::cout << "------\n";
  std::cout << stockSpanner->next(70) << '\n';  // return 2
  std::cout << stockSpanner->next(60) << '\n';  // return 1
  std::cout << stockSpanner->next(75) << '\n';
  std::cout << stockSpanner->next(85) << '\n';  // return 6

  return 0;
}