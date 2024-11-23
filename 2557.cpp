#include "utils.hpp"

class Solution {
public:
    int maxCount(vector<int>& banned, int n, long long maxSum) {
        // remove duplicate in banned vector
        set<int> tmp(banned.begin(), banned.end());
        banned.assign(tmp.begin(), tmp.end());

        // create presums array
        sort(banned.begin(), banned.end());
        vector<long long> presums(banned.size() + 1, 0);
        for (int idx = 1 ; idx <= banned.size(); idx++)
            presums[idx] = presums[idx - 1] + banned[idx - 1];

        // binary search
        int left = 0, right = n;
        while(left < right) {
            int mid = right - (right - left) / 2;
            if (isOK(presums, banned, mid, maxSum))
                left = mid;
            else
                right = mid - 1;
        }

        int num_banned = upper_bound(banned.begin(), banned.end(), left) - banned.begin();

        return left - num_banned;
    }
    bool isOK(const vector<long long> &presums, const vector<int> &banned, long long num, long long maxSum) {
        long long sum = (1 + num) * num / 2;
        /* 
            num=3
            2 3 8
                ^
         */
         int idx = upper_bound(banned.begin(), banned.end(), num) - banned.begin();
         sum -= presums[idx];
         return sum <= maxSum;
    }
};

/* 
    Approach 2: O(mlogm + log(n)*log(m))
        m = banned.size()
        mlogm : Sorting banned vector
        log(n) * log(m): binary search in range of n nested with binary search in banned vector
    
    Approach 1: brute force. O(n)
        sum = 0
        count = 0
        for i from 1 to n:
            if i is not in banned
                sum += i
                count++
            if sum > maxSum
                break
 
    i=1 check 1,4,6
    i=2 check 1,4,6
    ...

    sum(1..n) = (1 + n) * n / 2
    i=1 => sum = 1
    i=2 => sum = 3
 */



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