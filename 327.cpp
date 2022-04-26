#include "utils.hpp"

/*
  nums = [-2,5,-1], lower = -2, upper = 2

  XXXXXYYYYY
  XXXXX  YYYYY

    nums =    X X X X X
  presum =  0 Y Y Y Y Y (記得補零)

  i => s.t.
   upper >= presum[j] - presum[i-1] >= lower

   presum[j] >= presum[i-1] + lower => count of larger number of self (315.cpp)
   presum[j] <= presum[i-1] + upper
 */
class Solution3 {
 public:
  vector<int> presums;
  int count = 0;
  int lower_, upper_;
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    presums.resize(n + 1, 0);
    lower_ = lower;
    upper_ = upper;
    for (int i = 0; i < n; i++) {
      presums[i + 1] = presums[i] + nums[i];
    }

    divideAndConquer(nums, 1, n);  // n = 3
    return count;
  }

  void divideAndConquer(const vector<int>& nums, int start, int end) {
    if (start > end) return;
    if (start == end) {
      if (nums[start - 1] <= upper_ && nums[start - 1] >= lower_) {
        ++count;
        return;
      }
    }
    int mid = (start + end) / 2;
    divideAndConquer(nums, start, mid);
    divideAndConquer(nums, mid + 1, end);

    // binary search
    /*
      XXXXXYYYYY
      [XXXXX] [YYYYY] ==> sorted range
       s           e

       lower = 2; upper = 4
       1 2 3 4 5
         l     u
     */
    auto begin = presums.begin();
    for (int i = start; i <= mid; i++) {
      auto l = lower_bound(begin + mid + 1, begin + end + 1,
                           presums[i - 1] + lower_);
      auto u = upper_bound(begin + mid + 1, begin + end + 1,
                           presums[i - 1] + upper_);
      count += (u - l);
    }

    // sorting range
    std::sort(begin + start, begin + end + 1);
  }
};

/*
  XXXXXXXXXX
   i    j
  要求 [i, j] range sum，需直覺想到 presum[j] - presum[i-1]

  XXXXXYYYYY
  XXXXX  YYYYY

    nums =    X X X X X
  presum =  0 Y Y Y Y Y (記得補零)

  i => s.t.
   upper >= presum[j] - presum[i-1] >= lower

   presum[j] >= presum[i-1] + lower => count of larger number of self (315.cpp)
   presum[j] <= presum[i-1] + upper
 */
class Solution2 {
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    lower_ = lower, upper_ = upper;
    presums.resize(n + 1);

    for (int i = 0; i < n; i++) {
      presums[i + 1] = presums[i] + nums[i];
    }
    divideAndConquer(1, n);
    return count;
  }

 private:
  int count = 0;
  vector<int> presums;
  int lower_, upper_;
  void divideAndConquer(int start, int end) {
    if (start >= end) return;

    int middle = (start + end) / 2;
    divideAndConquer(start, middle);
    divideAndConquer(middle + 1, end);

    for (int i = start; i <= middle; i++) {
      auto a = lower_bound(presums.begin() + middle + 1,
                           presums.begin() + end + 1, presums[i] + lower_);
      auto b = upper_bound(presums.begin() + middle + 1,
                           presums.begin() + end + 1, presums[i] + upper_);
      count += b - a;
    }

    // sort
    int left = start, right = middle + 1;
    int range_len = end - start + 1;
    vector<int> temp(range_len);
    for (int i = 0; i < range_len; i++) {
      if (right > end) {
        temp[i] = presums[left];
        left++;

      } else if (left > middle) {
        temp[i] = presums[right];
        right++;
      } else if (presums[left] < presums[right]) {
        temp[i] = presums[left];
        left++;
      } else {
        temp[i] = presums[right];
        right++;
      }
    }

    for (int i = 0; i < range_len; i++) {
      presums[start + i] = temp[i];
    }

    print(presums);
  }
};

/*
    Calculate range sum of XYZ ==>
    1. X Y Z
    2. XY Z
       X YZ <== Skipped
    3. XYZ
 */

/* 這樣會有大錯！！！！
    ex:
    [100, 200, 300] 經過以下 divide and conquer，會沒有計算到 [1, 2] 區間！！
    divideAndConquer(nums, 0, 2)
    ==> [0, 0]
    ==> [1, 1]
    ==> [2, 2]
    ==> [0, 1]
    ==> [0, 2]
 */
class Solution {
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    /* Should not decalrae member variables twice here */
    // int lower_ = lower, upper_ = upper;
    lower_ = lower, upper_ = upper;
    divideAndConquer(nums, 0, n - 1);
    return count;
  }

 private:
  int count = 0;
  int lower_, upper_;
  int divideAndConquer(vector<int>& nums, int start, int end) {
    if (start > end) return 0;
    cout << "----------\n";
    print(nums);
    if (start == end) {
      if (nums[start] >= lower_ && nums[start] <= upper_) count += 1;
      cout << "start : " << start << " | end: " << end << '\n';
      cout << "sum: " << nums[start] << '\n';
      cout << "count: " << count << '\n';
      return nums[start];
    }

    int mid = (start + end) / 2;
    int sum = divideAndConquer(nums, start, mid) +
              divideAndConquer(nums, mid + 1, end);
    if (sum >= lower_ && sum <= upper_) count += 1;

    cout << "lower_ : " << lower_ << " | upper_: " << upper_ << '\n';
    cout << "start : " << start << " | end: " << end << '\n';
    cout << "sum: " << sum << '\n';
    cout << "count: " << count << '\n';
    return sum;
  }
};

// A: [XXXXXYYYYY]
// B: [XXXXX] C:[YYYYY]

int main() {
  vector<int> nums{-2, 5, -1};
  int lower = -2;
  int upper = 2;
  Solution3 sol;
  int ans = sol.countRangeSum(nums, lower, upper);
  cout << "ans: " << ans << '\n';

  return 0;
}
