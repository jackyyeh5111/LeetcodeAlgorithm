/* 
    Time limit exceed
    自己想的！
 */
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
      long ans = 0;
      long modulo = 1e9 + 7;
      for (int i = 0; i < arr.size(); i++) {
        // search left
        int num_left = 0;
        for (int j = i - 1; j >= 0; j--) {
          if (arr[j] <= arr[i])
            break;
          num_left++;
        }

        // search right
        int num_right = 0;
        for (int j = i + 1; j < arr.size(); j++) {
          if (arr[j] < arr[i])
            break;
          num_right++;
        }

        ans += ((long)arr[i] * (1 + num_left + num_right + num_left * num_right)) % modulo;
      }
      return (int)(ans % modulo);
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