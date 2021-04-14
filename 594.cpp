/***** Second Visit *****/
/*
    for each num, find the longest harmonious subsequence so far ends up with num.
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        int ans=0;
        unordered_map<int,int> mp;
        for (int num:nums) {
            mp[num]++;
            int k=max(mp[num+1],mp[num-1]);
            if (k!=0) ans=max(ans,k+mp[num]);
        }
        return ans;
    }
};

/***** First Visit *****/
/*
    Its maximum value and its minimum value is exactly 1.
    Sort + 2 ptr.
    1 2 2 2 3 3 5 7
                ^
                ^
    T:O(nlogn)/S:O(1)
    -----
    Use a hashmap and check up/low value if exist.
    T:O(n)/S:O(n)
*/

// T:O(n)/S:O(n) 1 pass
class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        unordered_map<int,int> mp;
        int ans=0;
        for (int num:nums) {
            mp[num]++;
            if (mp.count(num+1)) ans=max(ans,mp[num]+mp[num+1]);
            if (mp.count(num-1)) ans=max(ans,mp[num]+mp[num-1]);
        }
        return ans;
    }
};

// T:O(n)/S:O(n) 2 pass
class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        unordered_map<int,int> mp;
        for (int num:nums) mp[num]++;
        int ans=0;
        for (auto it=mp.begin(); it!=mp.end(); ++it) {
            int num=it->first;
            if (mp.count(num+1)) ans=max(ans,it->second+mp[num+1]);
            if (mp.count(num-1)) ans=max(ans,it->second+mp[num-1]);
        }
        return ans;
    }
};

// T:O(nlogn)/S:O(1) 2 pass
class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int n=nums.size(), ans=0, l=0, r=0;
        while (r<n) {
            while(r<n-1&&abs(nums[r+1]-nums[l])<=1) r++;
            if (abs(nums[r]-nums[l])==1)ans=max(ans,r-l+1);
            r++;
            while(l<r&&r<n&&abs(nums[r]-nums[l])>1)l++;
        }
        return ans;
    }
};
