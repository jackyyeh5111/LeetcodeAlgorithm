class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = N - 1;
        int ans = 0;
        const int mod = 1e9 + 7;

        vector<int> power(N);
        power[0] = 1;
        for (int i = 1; i < N; i++)
            power[i] = power[i-1] * 2 % mod;

        while(left <= right) { // left = 2, right = 1
            if (nums[left] + nums[right] > target) // 11 > 9
                right--;
            else {
                // subsequences that contains left idx and at most right idx
                ans = (ans % mod + power[right - left] % mod) % mod;
                left++;
            }
        }
        return ans;
    }
};

/* 
    [3 5 6 7]

    min: 2
    max: 2
    sum: 4
    tgt: 4
    # non-empty subsequences: 3 + 1 
 */

/* 
    clarification:
    1. [3] min: 3, max: 3
    
    edge:
    1. no empty nums

    nums: [1 2 5 3]
    nums: [1 2 3 5]
             l
             r
 
    subsequences: [1 2 3]

    min: 2
    max: 2
    sum: 4
    tgt: 4
    # non-empty subsequences: 3 + 1
 */


