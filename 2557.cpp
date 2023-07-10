#include "utils.hpp"
/*
    arr =       1 2 3
    presums:  0 1 3 6

    ban = [1,4,6]
    n = 6
    maxSum = 4
 */

class Solution {
 public:
  vector<long long> presums;
  int maxCount(vector<int>& banned, int n, long long maxSum) {
    // remove duplicated numbers in banned
    set<int> tmp(banned.begin(), banned.end());
    banned.assign(tmp.begin(), tmp.end());

    sort(banned.begin(), banned.end());
    presums.resize(banned.size() + 1);
    for (int i = 0; i < banned.size(); ++i) {
      presums[i + 1] = presums[i] + banned[i];
    }

    // left = 1, right = 2, mid = 1
    while (left < right) {
      int middle = right - (right - left) / 2;
      if (isOk(middle, banned, maxSum))
        left = middle;
      else
        right = middle - 1;
    }

    // int left = 1, right = n;
    // while (left < right) {
    //   int middle = right - (right - left) / 2;
    //   if (!isOk(middle, banned, maxSum))
    //     right = middle - 1;
    //   else
    //     left = middle;
    // }
    
    // int left = 1, right = n - 1;
    // while (left != right) {
    //   int middle = left + (right - left) / 2;
    //   if (isOk(middle, banned, maxSum))
    //     left = middle + 1;
    //   else
    //     right = middle;
    // }

    int target = left;

    int num_banned =
        upper_bound(banned.begin(), banned.end(), target) - banned.begin();
    return target - num_banned;
  }

  bool isOk(long long M, const vector<int>& banned, long long maxSum) {
    int idx = upper_bound(banned.begin(), banned.end(), M) - banned.begin();
    long long sum = (1 + M) * M / 2;
    sum -= presums[idx];
    return sum <= maxSum;
  }
};

int main(int argc, char** argv) {
  Solution sol;
  vector<int> banned{1, 1};
  int n = 2, maxSum = 2;
  std::cout << sol.maxCount(banned, n, maxSum) << '\n';

  return 0;
}