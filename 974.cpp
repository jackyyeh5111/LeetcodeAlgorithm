hehe haha can you see me~


/*
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

-----Base Test Case-----
Input: nums = [5,4,1,3,2,1], k = 5
Output: 6
Explanation: There are 6 subarrays with a sum divisible by k = 5:
[5], [4,1], [5,4,1], [3,2], [4,1,3,2], [5,4,1,3,2]

  nums =   [5,4,1,3,2,1]
            0   2
presums= [0,5,9,10,...]
                 ^
          ^
sum(nums[i:j]) = presums[j+1] - preusms[i]
i = 0, j = 2

ans = 0
for i in nums.size():
    for j in nums.size():
        if ((presums[j+1] - preusms[i]) % k == 0)
            ans++

optimized:
    hashmap:
        0: 1
        1:
        2:
        3:
        4:

    presums[j+1] - preusms[i] = subarr_sum
    preusms[i] = subarr_sum - presums[j+1]
    
      nums =   [5,4,1,3,2,1]
    presums= [0,5,9,10,...]
    
    i = 0:
        5 % 5 == 0 (check how many previous (subarray sum % 5) == 0)
        presum % 5 == 1 ()
*/

/*
    k = 2
    nums =     [1,2,4]
    presums= [0,1,3,7]
*/
int divisibleByK(vector<int> &nums, int k) {
    // create presum arrs
    vector<int> presums(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++)
        presums[i + 1] = nums[i] + presums[i];
    
    // create presum_cnt hashmap
    unordered_map<int, int> presum_cnt;
    presum_cnt[0] = 1;
    
    /*
        k = 2
        nums =     [1,2,4]
        presums= [0,1,3,7]
        
        presum_cnt:
            0: 1
            1: 3
    
    
        presums[j+1] - preusms[i] = subarr_sum
        
        4 - (-1) = 5 % 5 == 0
        remainder = 4
        
        5 - abs(-1) % 5 => k - ( abs(negative_val) % k )
        
        ((v % k) + k )% k
    
    */
    
    // iterate through preusma arr
    int ans = 0;
    for (int i = 1; i <= nums.size(); i++) { // i = 4
        int remainder = presums.at(i) % k; // 7 % 2 == 1
        ans += presum_cnt[remainder]; // 3
        presum_cnt[remainder]++;   
    }
    return ans; // 3
}




