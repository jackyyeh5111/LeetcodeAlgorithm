class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        long modulo = 1e9 + 7;

        // create power lookup table in advance (avoid pow() operation out of range)
        vector<long> powers(size);
        powers[0] = 1.0;
        for (int i = 1; i < size; i++) {
            powers[i] = (powers[i - 1] * 2) % modulo;
        }

        // starting at left element, how many subsequences can meet requirements?
        // two pointers approach
        long ans = 0;
        int left = 0, right = size - 1;
        while(left <= right) {
            if (nums[left] + nums[right] > target)
                right--;
            else {
                ans = (ans + powers[right - left]) % modulo;
                left++;
            }
        }
        return (int)ans;
    }
};

/* 
    Note: Sorting does not affect result

    target: 3
    arr: [1 1 2 2]
          l
                r

    When start at left element, how many subsequences can meet requirements?
        ans: 2^(right - left)

    edge case: // array only got one element
        target: 3
        arr: [1]
              l
              r
*/