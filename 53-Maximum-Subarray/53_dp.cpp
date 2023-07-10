#include <cmath>
#include <iostream>
#include <vector>

/*
  dp: space O(n) -> O(1)

  definition =>
  dp[i]: the subarray with the largest sum ending at nums[i]

  X [X X i] X X
  dp[i] = max(dp[i-1], dp[i-1] + nums[i]) (wrong)
  dp[i] = max(nums[i], dp[i-1] + nums[i]) (corret)

  可以看出 dp[i] only related to dp[i-1], therefore we can reduce the dp array storage into a variable.
 */
class Solution7 {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, INT_MIN);

        // status init
        int sum = nums[0];

        // transfer function
        int ans = sum;
        for (int i = 1; i < N; ++i) {
            sum = max(nums[i], sum + nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};

/* 
  dynamic programing (Basic I (时间序列型))

  definition =>
  dp[i]: the subarray with the largest sum ending at nums[i]

  X [X X i] X X
  dp[i] = max(dp[i-1], dp[i-1] + nums[i]) (wrong)
  dp[i] = max(nums[i], dp[i-1] + nums[i]) (corret)

  可以看出 dp[i] only related to dp[i-1], therefore we can reduce the dp array storage into a variable.
 */
class Solution6 {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, INT_MIN);

        // status init
        dp[0] = nums[0];

        // transfer function
        int ans = nums[0];
        for (int i = 1; i < N; ++i) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


/* 
  ref:
  https://leetcode.com/problems/maximum-subarray/solutions/20452/c-dp-and-divide-and-conquer/?q=divide&orderBy=hot
 
  另外一種 divideAndConquer 思考方式，Solution4 是把 array [A A A B B B]分成
  - [A A A] [B B B] 兩個 subarray 看待
  這題是是分左右兩邊加上自己
  - [A A] [A] [B B B]
 */
class Solution5 {
public:
    vector<int> presums;
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        presums.resize(N+1);
        for (int i = 1; i <= N; ++i) 
            presums[i] = nums[i-1] + presums[i-1];
        return divideAndConquer(nums, 0, N-1);
    }
    int divideAndConquer(const vector<int> &nums, int start, int end) {
        if (start > end) return INT_MIN;
        int mid = start + (end - start) / 2;
        int left_sum = divideAndConquer(nums, start, mid - 1);
        int right_sum = divideAndConquer(nums, mid + 1, end);
        int lmax = 0, rmax = 0;
        for (int i=start; i <= mid-1; ++i)
            lmax = max(lmax, presums[mid] - presums[i]);
        for (int i=mid+1; i <= end; ++i)
            rmax = max(rmax, presums[i+1] - presums[mid+1]);
        return max(max(left_sum, right_sum), lmax + rmax + nums[mid]);
    }
};



/* 
  [A]: start = 0, end = 1, mid = 0

  1.   [A A] [B B B]
  2.   [A A B B B]
  ps: 0 X X
 
  nums[i:j] = presums[j+1] - presums[i] (這裡 idx 需要特別小心)

  另外一個實作方法，使用 end 為閉區間來實作
 */

class Solution4 {
public:
    vector<int> presums;
    int ans = INT_MIN;
    int maxSubArray(vector<int>& nums) {
      int N = nums.size();
      
      // init presums
      presums.resize(N + 1);
      for (int i = 1; i <= N; ++i) {
        presums[i] = nums[i-1] + presums[i-1];
      }

      divideAndConquer(nums, 0, N-1);
      return ans;
    }

    void divideAndConquer(const vector<int> &nums, int start, int end) {
        if (start > end) return;
        if (start == end) {
          ans = max(nums[start], ans);
          return;
        }
        int mid = start + (end - start) / 2;
        divideAndConquer(nums, start, mid);
        divideAndConquer(nums, mid + 1, end);

        int left_sum = INT_MIN, right_sum = INT_MIN;
        for (int i = start; i <= mid; ++i) {          
          left_sum = max(left_sum, presums[mid+1] - presums[i]);
        }
        for (int i = mid + 1; i <= end; ++i) {          
          right_sum = max(right_sum, presums[i+1] - presums[mid+1]);
        }
        ans = max(ans, left_sum + right_sum);
    }
};



/*
     nums:   X X X
  presums: 0 S S S
             i   j

  sum of nums[i, j]: presums[j] - presums[i-1]
 */
class Solution3 {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    presums.resize(n + 1, 0);
    for (int i = 0; i < n; i++) {
      presums[i + 1] = presums[i] + nums[i];
    }

    divideAndConquer(1, n);
    return max_sum;
  }

 private:
  int max_sum = INT_MIN;
  vector<int> presums;
  void divideAndConquer(int start, int end) {
    if (start > end) return;
    if (start == end) {
      max_sum = max(max_sum, presums[start] - presums[start - 1]);
      return;
    }

    int mid = (start + end) / 2;
    divideAndConquer(start, mid);
    divideAndConquer(mid + 1, end);

    int left_sum = INT_MIN;
    for (int i = mid; i >= start; i--) {
      left_sum = max(left_sum, presums[mid] - presums[i - 1]);
    }

    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= end; i++) {
      right_sum = max(right_sum, presums[i] - presums[mid]);
    }

    max_sum = max(max_sum, left_sum + right_sum);
  }
};

/* wrong answer at testing case:
  [-2,1]
*/
class Solution3_1 {
public:
    vector<int> presums;
    int ans = INT_MIN;
    int maxSubArray(vector<int>& nums) {
      int N = nums.size();
      
      // init presums
      presums.resize(N + 1);
      for (int i = 1; i <= N; ++i) {
        presums[i] = nums[i-1] + presums[i-1];
      }

      divideAndConquer(nums, 0, N);
      return ans;
    }

    void divideAndConquer(const vector<int> &nums, int start, int end) {
        if (start >= end) return;
        if (start + 1 == end) {
          ans = max(nums[start], ans);
          return;
        }
        int mid = start + (end - start) / 2;
        divideAndConquer(nums, start, mid);
        divideAndConquer(nums, mid + 1, end);

        int left_sum = INT_MIN, right_sum = INT_MIN;
        for (int i = start; i < mid; ++i) {          
          left_sum = max(left_sum, presums[mid] - presums[i]);
        }
        for (int i = mid; i < end; ++i) {          
          right_sum = max(right_sum, presums[i+1] - presums[mid]);
        }
        ans = max(ans, left_sum + right_sum);
    }
};

/* 
  [A]: start = 0, end = 1

  1.   [A A] [B B B]
  2.   [A A B B B]
  ps: 0 X X
 
  nums[0:N] = presums[N] - presums[0]
 */





/*
     nums:   X X X
  presums: 0 S S S
             i   j

  sum of nums[i, j]: presums[j] - presums[i-1]
 */
class Solution2 {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    presums.resize(n + 1, 0);
    for (int i = 0; i < n; i++) {
      presums[i + 1] = presums[i] + nums[i];
    }

    divideAndConquer(1, n);
    return max_sum;
  }

 private:
  int max_sum = INT_MIN;
  vector<int> presums;
  void divideAndConquer(int start, int end) {
    if (start > end) return;
    if (start == end) {
      max_sum = max(max_sum, presums[start] - presums[start - 1]);
      return;
    }

    int mid = (start + end) / 2;
    divideAndConquer(start, mid);
    divideAndConquer(mid + 1, end);

    /* 用雙層 for 浪費時間，只要從中間開始往兩邊展開即可 */
    for (int i = start; i <= mid; i++) {
      for (int j = mid + 1; j <= end; j++) {
        max_sum = max(max_sum, presums[j] - presums[i - 1]);
      }
    }
  }
};

/* Divide and conquer
    ref:
    https://leetcode.com/problems/maximum-subarray/discuss/540951/C%2B%2B-divide-and-conquer-solution
*/

class Solution {
 public:
  std::vector<int> arr;

  int sumCross(int left, int right, int mid) {
    // left sum
    int sum = arr[mid];
    int sum_left = arr[mid];
    for (int i = mid - 1; i >= left; i--) {
      sum += arr[i];
      sum_left = std::max(sum_left, sum);
    }

    // right sum
    sum = arr[mid + 1];
    int sum_right = arr[mid + 1];
    for (int i = mid + 2; i < right; i++) {
      sum += arr[i];
      sum_right = std::max(sum_right, sum);
    }

    return sum_left + sum_right;
  }

  int helper(int left, int right) {
    if (left >= right) {
      return arr.at(left);
    }

    int mid = (left + right) / 2;
    int sum_left = helper(left, mid);
    int sum_right = helper(mid + 1, right);
    int sum_cross = sumCross(left, right, mid);

    return std::max(sum_cross, std::max(sum_left, sum_right));
  }

  int maxSubArray(std::vector<int>& nums) {
    int n = nums.size();
    arr = nums;
    return helper(0, n - 1);
  }
};

int main(int argc, char** argv) {
  Solution sol;
  std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::cout << sol.maxSubArray(nums) << '\n';

  nums = {1};
  std::cout << sol.maxSubArray(nums) << '\n';
  return 0;
}