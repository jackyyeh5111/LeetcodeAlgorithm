#include "../utils.hpp"


//   ref: https://www.youtube.com/watch?v=kln9xC6GGYQ
//   ref: (還沒看)
//       https://leetcode.com/problems/sort-colors/discuss/26500/Four-different-solutions

//   可以把 RGB 想成數字 0, 1, 2，這題其實就是很間單的對只包含 [0, 1, 2] arr
//   做排序

//         p1 p2
//   0  0  0  1  2  2
//            p0
//   break if p0 > p2
//   p0++ just after each swap

//   Input: nums = [2,0,2,1,1,0]
//   Output: [0,0,1,1,2,2]

class Solution2
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int p0 = 0, p1 = 0, p2 = n - 1;

        while (p0 <= p2) {
            if (nums[p0] == 0) {
                // 這裡之所以可以一起 p0++，因為 p0 一開始跟 p1
                // 從同個位置開始，所以從 p1 idx swap 過來的數值一定不會是 B
                swap(nums[p0], nums[p1]);
                p1++;
                p0++;
            } else if (nums[p0] == 2) {
                swap(nums[p0], nums[p2]);
                p2--;
            } else {
                p0++;
            }
        }
    }
};

/* Wrong here!
   input: [1, 2, 0]，testing failed.
*/
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int p0 = 0, p1 = 0, p2 = n - 1;  // p2 = 2

        // nums = [1, 2, 0]
        while (p0 <= p2) {  // p0 = 1, p2 = 2
            if (nums[p0] == 0) {
                swap(nums[p0], nums[p1]);
                p1++;
            } else if (nums[p0] == 2) {
                swap(nums[p0], nums[p2]);
                p2--;
            }
            p0++;
        }
    }
};