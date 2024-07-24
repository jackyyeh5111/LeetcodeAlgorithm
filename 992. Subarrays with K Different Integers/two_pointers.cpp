class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }

    int atmost(const vector<int> &nums, int k) {
        int left = 0, right = 0;
        int ans = 0, num_unique = 0;
        unordered_map<int, int> num_counter; // num -> count

        /* 
            k = 2
            [1, 2, 1, 2, 3]
                      l
                         r
                
            num_counter = {
                1: 1
                2: 1
            }
         */
        int count = 0;
        for (; right < nums.size(); right++) {
            num_counter[nums[right]]++;
            if (num_counter[nums[right]] == 1)
                num_unique++;
            while(num_unique > k) {
                num_counter[nums[left]]--;
                if (num_counter[nums[left]] == 0)
                    num_unique--;
                left++;
            }

            count += right - left + 1;
        }
        return count;
    }
};

/* 
    Record unique number between nums[l:r]

    [1, 2, 1, 2, 3]
     l
           r

    num_counter = { // num -> count
        1: 1
        2: 1
    }

    If count 0 -> 1:
        num_unique++
    count 1 -> 0:
        num_unique--
 */