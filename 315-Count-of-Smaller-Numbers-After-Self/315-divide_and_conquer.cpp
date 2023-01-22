#include "../utils.hpp"

/*
A: [X X X X X Y Y Y Y Y]
B: [X X X X X] C:[Y Y Y Y Y]
 */

class Solution3 {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    count.resize(n, 0);
    vector<int> sorted_num = nums;
    divideAndConquer(nums, sorted_num, 0, n - 1);

    return count;
  }

 private:
  vector<int> count;
  void divideAndConquer(const vector<int>& nums, vector<int>& sorted_num,
                        int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;
    divideAndConquer(nums, sorted_num, start, mid);
    divideAndConquer(nums, sorted_num, mid + 1, end);

    for (int i = start; i <= mid; i++) {
      auto pos = lower_bound(sorted_num.begin() + mid + 1,
                             sorted_num.begin() + end + 1, nums[i]);
      count[i] += (pos - (sorted_num.begin() + mid + 1));
    }

    // 這裡的 sort 真是神來一筆！
    sort(sorted_num.begin() + start, sorted_num.begin() + end + 1);
  }
};

class Solution2 {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    count.resize(n, 0);
    vector<int> sorted_num = nums;
    divideAndConquer(sorted_num, 0, n - 1);

    return count;
  }

 private:
  vector<int> count;
  void divideAndConquer(vector<int>& sorted_num, int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;
    divideAndConquer(sorted_num, start, mid);
    divideAndConquer(sorted_num, mid + 1, end);

    for (int i = start; i <= mid; i++) {
      /* Wrong here! Index between sorted_num and count are not matched. */
      auto pos = lower_bound(sorted_num.begin() + mid + 1,
                             sorted_num.begin() + end + 1, sorted_num[i]);
      count[i] += (pos - (sorted_num.begin() + mid + 1));
    }

    sort(sorted_num.begin() + start, sorted_num.begin() + end + 1);
  }
};

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    count.resize(n, 0);
    vector<int> sorted_num = nums;
    divideAndConquer(sorted_num, 0, n - 1);

    return count;
  }

 private:
  vector<int> count;
  void divideAndConquer(vector<int>& sorted_num, int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;
    divideAndConquer(sorted_num, start, mid);
    divideAndConquer(sorted_num, mid + 1, end);

    /* Wrong pointer operation! Be careful about the boundary*/
    for (int i = start; i <= mid; i++) {
      auto pos = lower_bound(sorted_num.begin() + mid + 1,
                             sorted_num.begin() + end, sorted_num[i]);
      count[i] += (pos - (sorted_num.begin() + mid + 1));
    }

    /* Wrong pointer operation! Be careful about the boundary*/
    sort(sorted_num.begin() + start, sorted_num.begin() + end);
  }
};

int main() {
  vector<int> nums{5, 2, 6, 1};
  SolutionTest sol;
  vector<int> ans = sol.countSmaller(nums);
  print(ans);
}