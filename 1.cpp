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
