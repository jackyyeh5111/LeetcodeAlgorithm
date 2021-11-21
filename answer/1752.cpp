// 2 pass T:O(n)
class Solution {
public:
    bool check(vector<int>& nums)
    {
        int n=nums.size();
        int start=0;
        for (int i=1; i<n; ++i) {
            if (nums[i]<nums[i-1]) start=i;
        }
        for (int i=1; i<n; ++i) {
            if (nums[(start+1)%n]<nums[start]) return false;
            else start=(start+1)%n;
        }
        return true;
    }
};

// 1 pass T:O(n)
class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]<nums[i-1])cnt++;
        }
        if(nums[0]<nums.back())cnt++;
        return cnt<=1;
    }
};
