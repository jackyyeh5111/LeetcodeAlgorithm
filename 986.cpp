#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/* visit 1 */
class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    firstList.insert(firstList.end(), secondList.begin(), secondList.end());
    std::sort(firstList.begin(), firstList.end());

    vector<vector<int>> ans;
    if (firstList.empty()) return ans;

    vector<int> prev_interval = firstList[0];
    for (int i = 1; i < firstList.size(); i++) {
      if (prev_interval[1] >= firstList[i][0]) {
        vector<int> intersect{std::max(prev_interval[0], firstList[i][0]),
                              std::min(prev_interval[1], firstList[i][1])};
        ans.push_back(intersect);

        prev_interval = {std::min(prev_interval[1], firstList[i][1]),
                         std::max(prev_interval[1], firstList[i][1])};
      } else {
        prev_interval = firstList[i];
      }
    }

    return ans;
  }
};

int main(int argc, char** argv) {
  Solution sol;
  vector<vector<int>> firstList = {{1, 7}};
  vector<vector<int>> secondList = {{3, 10}};
  for (vector<int> ans : sol.intervalIntersection(firstList, secondList)) {
    for (int n : ans) std::cout << n << ' ';
    std::cout << '\n';
  }
  std::cout << '\n';

  //   intervals = {{1, 3}, {6, 9}};
  //   newInterval = {2, 5};
  //   for (vector<int> ans : sol.insert(intervals, newInterval)) {
  //     for (int n : ans) std::cout << n << ' ';
  //     std::cout << '\n';
  //   }
  //   std::cout << '\n';

  return 0;
}