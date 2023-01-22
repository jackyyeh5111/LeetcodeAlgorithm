#include "../utils.hpp"

/* if condition 如果放在 for loop 開頭，會更直覺，不然 index ++i 很容易忘了計算 
    Note:
        放在結尾是 if (i == p2) break;
        放在開頭是 if (i > p2) break;
*/
class Solution2 {
 public:
  void sortColors(vector<int>& nums) {
    int p0 = 0, p2 = nums.size() - 1;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > p2) break;
      if (nums[i] == 0) {
        swap(nums[i], nums[p0]);
        ++p0;
      }
      if (nums[i] == 2) {
        swap(nums[i], nums[p2]);
        --p2;
        --i;
      }
    }
  }
};

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int p0 = 0, p2 = nums.size() - 1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        swap(nums[i], nums[p0]);
        ++p0;
      }
      if (nums[i] == 2) {
        swap(nums[i], nums[p2]);
        --p2;
        --i;
      }

      if (i == p2) break;
    }
  }
};

int main(int argc, char** argv) {
  std::vector<int> nums{2, 0, 2, 1, 1, 0};
  Solution sol;
  sol.sortColors(nums);
  print(nums);

  return 0;
}