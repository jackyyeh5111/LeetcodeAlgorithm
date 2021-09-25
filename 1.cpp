/***** Third Visit *****/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int> mp;
        int n=nums.size();
        for (int i=0; i<n; ++i) {
            if (mp.count(target-nums[i]))
                return {mp[target-nums[i]],i};
            mp[nums[i]]=i;
        }
        return {};
    }
};

/***** Second Visit *****/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int> mp;
        for (int i=0; i<nums.size(); ++i) {
            if (mp.count(target-nums[i]))
                return {i,mp[target-nums[i]]};
            mp[nums[i]]=i;
        }
        return {};
    }
};

/***** First Visit *****/
/*
    brute force
    enumerate all pair then check sum
    T:O(n^2)/S:O(1)
    -----
    Use a hashmap. k: num, v: idx
    for loop to find compensate num/idx.
    T:O(n)/S:O(n)
    -----
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int> m;
        int n=nums.size();
        for (int i=0; i<n; ++i) {
            int num=nums[i], compensate=target-num;
            if (m.find(compensate)!=m.end())
                return vector<int>{m[compensate],i};
            m[num]=i;
        }
        return vector<int>{};
    }
};
