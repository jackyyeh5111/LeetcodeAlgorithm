/******************* Boyer-Moore Voting Algorithm(DP) *******************/
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        /*
            majority number appears more than n/2 times.
            If there's a majority num, it must exist in the mid of sorted array.
            -> sort+return mid
            T:O(nlogn),S:O(1)
            ------------------------
            T:O(n), S:O(n) with a hashmap saving frequency.
            ------------------------
            finding k th smallest num:
            avg T:O(n), worst T:O(n^2)
            -----------------------
            Boyer-Moore Voting Algorithm
            2 2 1 1 1 2 2
            1 2 1 0 1 0 1
            Use DP!!!
            dp[i]=the majority from 0-i
            dp[i]=dp[i-1] if count>0 else num[i]

            ex. [7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]
        */
        int majority=nums[0];
        int count=1, size=nums.size();
        for (int i=1; i<size; ++i) {
            if (count==0) majority=nums[i];
            if (nums[i]==majority) count++;
            else count--;
        }
        return majority;
    }
};

/************************ hashmap ************************/
class Solution {
public:
    // T:O(n), S:O(n)
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int,int> m;
        int size=nums.size();
        for (int num:nums){
            m[num]++;
            if (m[num]>size/2) return num;
        }
        return -1;
    }
};
