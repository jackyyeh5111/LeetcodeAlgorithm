#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/* ref:
   https://leetcode.com/problems/insert-interval/discuss/844523/C%2B%2B-Super-Clean-Clear-Short-and-Simple-Solution-O(n)-time-O(1)-space
 */

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size(); i++) {
      if (intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
      } else if (intervals[i][0] > newInterval[1]) {
        ans.push_back(newInterval);
        ans.insert(ans.end(), intervals.begin() + i, intervals.end());
        return ans;
      } else {
        newInterval[0] = std::min(intervals[i][0], newInterval[0]);
        newInterval[1] = std::max(intervals[i][1], newInterval[1]);
      }
    }

    ans.push_back(newInterval);
    return ans;
  }
};

int main(int argc, char** argv) {
  Solution sol;
  vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> newInterval = {4, 8};
  for (vector<int> ans : sol.insert(intervals, newInterval)) {
    for (int n : ans) std::cout << n << ' ';
    std::cout << '\n';
  }
  std::cout << '\n';

  intervals = {{1, 3}, {6, 9}};
  newInterval = {2, 5};
  for (vector<int> ans : sol.insert(intervals, newInterval)) {
    for (int n : ans) std::cout << n << ' ';
    std::cout << '\n';
  }
  std::cout << '\n';

  return 0;
}