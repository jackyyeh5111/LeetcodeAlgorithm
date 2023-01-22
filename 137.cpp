#include "utils.hpp"

/*
可以直接用 int 來當作 bit vector！
因為最後會取 mod 3，所以實質上只需要用兩個 int 來儲存每個位元的 mod 即可

ex:

int bit1(高位元), bit2(低位元)
1. 00 --> bit1(i) == 0 && bit2(i) == 0 // i 位元最後 mod 為 0
2. 01 --> bit1(i) == 0 && bit2(i) == 1 // i 位元最後 mod 為 1
3. 10 --> bit1(i) == 1 && bit2(i) == 0 // i 位元最後 mod 為 2

  00 -> 01
  01 -> 10
  10 -> 11
  11 -> 00 (只有三進位，此項不考慮)

*/
class Solution2 {
 public:
  int singleNumber(vector<int>& nums) {
    int bit1 = 0, bit2 = 0;
    for (auto num : nums) {
      for (int i = 0; i < 32; i++) {
        int new_bit = ((num >> i) & 1);
        if (!new_bit) continue;

        // 00 -> 01
        // 01 -> 10
        // 10 -> 11
        // 11 -> 00 (只有三進位，此項不考慮)
        int high = (bit1 >> i) & 1;
        int low = (bit2 >> i) & 1;
        if (!high && !low) {
          bit2 += 1 << i;
        } else if (!high && low) {
          bit1 += 1 << i;
          bit2 -= 1 << i;
        } else if (high && !low) {
          bit1 -= 1 << i;
        } else {
          cout << "error!!\n";
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < 32; i++) {
      int lo = (bit2 >> i) & 1;
      ans += (lo << i);
    }

    return ans;
  }
};

/* Space 可以再優化 */
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    vector<int> bits(32, 0);
    for (auto num : nums) {
      for (int i = 0; i < 32; i++) {
        bits[i] += ((num >> i) & 1);
      }
    }

    int ans = 0;
    for (int i = 0; i < 32; i++) {
      ans += ((bits[i] % 3) << i);
    }
    return ans;
  }
};

int main() {
  vector<int> nums{30000, 500, 100, 30000, 100, 30000, 100};
  SolutionTest sol;
  int ans = sol.singleNumber(nums);
  cout << "ans: " << ans << '\n';
  return 0;
}