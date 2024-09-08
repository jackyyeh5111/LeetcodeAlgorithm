/* 
    3 1 2 4
    
    3 => 1 x 1 = 1
    XX1YY => 3 x 3 = 9 possible subarray with minimum 1
    3 3 => if duplicate number exists, use only one array (extend left pointer only)
    l

    min([3]) = 3
    min([3, 1]) = 1
    min([3, 1, 2]) = 1
    min([3, 1, 2, 4]) = 1
 */
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long sum = 0;
        long modulo = 1e9 + 7;
        for (int idx = 0; idx < arr.size(); idx++) {
            int left = idx - 1, right = idx + 1;
            while(left >= 0 && arr[left] >= arr[idx])
                left--;
            while(right < arr.size() && arr[right] > arr[idx])
                right++;
            long num_arr = (right - idx) * (idx - left);
            sum = (sum + (num_arr * arr[idx]) % modulo) % modulo;
        }
        return (int)(sum % modulo);
    }
};


/* 
    Clarification:
    1. arr[i] is not unique.

    Based on each element, see how far can be extended.

    [X X X] 1 [Y Y]
    
    total num arr: 1 + num_x + num_y + num_x * num_y

            3 1 2 4
       left 0 1 0 0
      right 0 2 1 0
    num_arr 1 6 2 1
    
    ans: 3 + 6 + 4 + 4

    How about adjacent elements are the same?

      nums: 3 3
      subarr:
        3
        3
        3 3

 */