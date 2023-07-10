#include "utils.hpp"

/* Wrong answer
  test case:
    3 3 3 1
 */
class Solution4 {
public:
    int totalFruit(vector<int>& fruits) {
        int N = fruits.size();
        if (N <= 2) return N;
        unordered_map<int, int> basket;
        if (fruits[0] == fruits[1])
          basket[fruits[0]] = 2;
        else {
          basket[fruits[0]] = 1;
          basket[fruits[1]] = 1;
        }

        int ans = 2;
        int left = 0, right = 2;
        /* 
            [0,1,2,2]
          */
        for (int right = 2; right < N; ++right) {
            ++basket[fruits[right]];
            if (basket[fruits[right]] == 1) {
              while (true) {
                --basket[fruits[left]];
                ++left;
                if (basket[fruits[left-1]] == 0) break;
              }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

/* Wrong answer
    test case:
    1 0 1 2 1 1
 */
class Solution3 {
public:
    int totalFruit(vector<int>& fruits) {
        int N = fruits.size();
        if (N <= 2) return N;
        pair<int, int> basket1{fruits[0], 1};
        pair<int, int> basket2{-1, 0};
        int ans = 2;
        for (int i = 1; i < N; ++i) {
            if (fruits[i] == basket1.first)
              ++basket1.second;
            else if (fruits[i] == basket2.first)
              ++basket2.second;
            else {
              if (fruits[i-1] == basket1.first)
                basket2 = {fruits[i], 1};
              else
                basket1 = {fruits[i], 1};
            }
            ans = max(ans, basket1.second + basket2.second);
        }
        return ans;
    }
};

class Solution2_5 {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int ans = 0, left = 0, right = 0, cnt = 0;
        for (int right = 0; right < fruits.size(); ++right) {
            ++basket[fruits[right]];
            if (basket[fruits[right]] == 1) ++cnt;
            while(cnt > 2) {
              --basket[fruits[left]];
              if (basket[fruits[left]] == 0) --cnt;
              ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

class Solution2 {
 public:
  int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    unordered_map<int, int> basket;

    int right = 0, left = 0, cnt = 0, ans = 0;
    while (right < n) {
      if (basket[fruits[right]] == 0) cnt++;
      basket[fruits[right]]++;

      while (cnt > 2) {
        basket[fruits[left]]--;
        if (basket[fruits[left]] == 0) cnt--;
        left++;
      }

      ans = max(ans, right - left + 1);
      right++;
    }

    return ans;
  }
};

/*
    ref:
    https://leetcode.com/problems/fruit-into-baskets/discuss/674800/C%2B%2B-2-solutions
 */

class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    unordered_map<int, int> um;
    int r = 0;
    int l = 0;
    int cnt = 0;
    int ans = 0;

    while (r < n) {
      if (um[fruits[r]] == 0) cnt++;
      um[fruits[r]]++;
      r++;

      while (l < r && cnt > 2) {
        um[fruits[l]]--;
        if (um[fruits[l]] == 0) cnt--;
        l++;
      }

      ans = max(ans, r - l);
    }

    return ans;
  }
};

int main(int argc, char** argv) {
  Solution2 sol;

  std::vector<int> nums{1, 2, 1};
  std::cout << sol.totalFruit(nums) << '\n';

  // nums = {0, 1, 2, 2};
  // std::cout << sol.totalFruit(nums) << '\n';

  // nums = {1, 2, 3, 2, 2};
  // std::cout << sol.totalFruit(nums) << '\n';

  // nums = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  // std::cout << sol.totalFruit(nums) << '\n';

  return 0;
}