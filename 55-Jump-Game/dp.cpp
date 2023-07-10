/* 
    Approah2: two pointers

                                2 3 1 1 4
    max idxs the ele can jump:  2 4.3.4.X
                                l   r
                                    l   r

                                3 2 1 0 4
    max idxs the ele can jump:  3 3.3.0.X
                                      ^   
    
                                5,9,3,2,1,0,2,3,3,1,0,0
    max idxs the ele can jump:  6 10.3.0.X
*/             
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        if (N == 1)
            return true;
        vector<int> dp(N);
        
        // init
        for (int i = 0; i < N; ++i)
            dp[i] = i + nums[i];

        int left = 0, right = dp[0];
        while(left < right) {
            int next = INT_MIN;
            while(left < right) {
                if (dp[left] >= N - 1)
                    return true;
                ++left;
                next = max(next, dp[left]);
            }
            right = next;
        }
        return false;
    }
};

/* 
    <Wrong answer>
    Fail case:
        [2,2,0,0,1]
    
    先算出每個 nums 位置，最遠可以跳到的 idx，一層一層推進，每一層都盡力跳到最遠的位置
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        if (N == 1)
            return true;
        vector<int> dp(N);
        
        // init
        for (int i = 0; i < N; ++i)
            dp[i] = i + nums[i];

        int ptr = 0;
        while(nums[ptr] != 0) {
            int next = INT_MIN;
            for (int i=ptr + 1; i <= min(dp[ptr], N-1); ++i) {
                if (dp[i] > next)
                    next = dp[i];
            }

            if (next >= N - 1)
                return true;
            ptr = next;
        }
        return false;
    }
};

/* 
                                2 3 1 1 4
    max idxs the ele can jump:  2 4.3.4.X
                                

                                3 2 1 0 4
    max idxs the ele can jump:  3 3.3.0.X
                                      ^   
 */             









