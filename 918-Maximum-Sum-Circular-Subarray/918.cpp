/* 
    Steps:
        Use Kadane's Algorithm to find the maximum subarray sum for the non-circular case.
        For the circular case:
        Compute the total sum of the array.
        Find the minimum subarray sum using Kadane's Algorithm applied on -nums.
        The maximum circular subarray sum will be total_sum - min_subarray_sum.
        Return the maximum of the two cases:
        The result from step 1.
        The result from step 2 (if it’s not zero; otherwise, fall back to step 1 to avoid an edge case where all numbers are negative).
 */
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
    
        // Step 1: Regular max subarray sum using Kadane's algorithm
        int max_sum = nums[0], current_max = nums[0];
        for (int i = 1; i < n; ++i) {
            current_max = std::max(nums[i], current_max + nums[i]);
            max_sum = std::max(max_sum, current_max);
        }

        // Step 2: Find the total sum of the array and the minimum subarray sum
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        int min_sum = nums[0], current_min = nums[0];
        for (int i = 1; i < n; ++i) {
            current_min = std::min(nums[i], current_min + nums[i]);
            min_sum = std::min(min_sum, current_min);
        }

        // Step 3: Calculate max circular subarray sum
        int max_circular_sum = total_sum - min_sum;

        // Step 4: Handle edge case where all numbers are negative
        if (max_circular_sum == 0) {
            return max_sum;
        }

        // Step 5: Return the maximum of both cases
        return std::max(max_sum, max_circular_sum);
    }
};

/* 
    [XXXX]
     i  j
    sum of subarray[i:j] = presums[j] - presums[i - 1]

    1 -1 2 1 -1 2
  0 1  0 2 3  

 */