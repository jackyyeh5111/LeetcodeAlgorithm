#include "utils.hpp"

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    diff &= -diff;

    int digit1 = 0, digit2 = 0;
    for (auto num : nums) {
      if ((num & diff) == 0)
        digit1 ^= num;
      else
        digit2 ^= num;
    }

    return {digit1, digit2};
  }
};

/*
    Algo:
    1. 先用 xor 一遍nums
       因為有兩個數字沒有成對，所以 xor 一定會有 x bit 為 1。
       由此得知，可以從 x bit 將此二數字分開
    2. 找隨便一個不同的 bit，這裡用找 rightmost different bit 為例子，不過找
       rightmost bit 有小技巧可以 O(1) 找到

        小技巧1
            a. x&(x-1)：　表示unset the rightmost set bit
            b. x^(x&(x-1))：　表示只保留 the rightmost set bit
        小技巧2
            a. x &= -x;  // 就這一步！！ 好猛

    3. 將 nums 根據 x bit 分成兩堆，兩堆再各做一次 xor，即可找到此二數
 */

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    if (diff == -2147483648)
      diff = 1;
    else
      diff &= -diff;  // 如果 diff == -2147483648 會 overflow

    int digit1 = 0, digit2 = 0;
    for (auto num : nums) {
      if ((num & diff) == 0)
        digit1 ^= num;
      else
        digit2 ^= num;
    }

    return {digit1, digit2};
  }
};
