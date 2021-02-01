/*
    running hashmap k: multiply, v:counts so far
    T:O(n^2)/S:O(n^2)
*/
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        int n=nums.size(), ans=0;
        for (int i=0; i<n-1; ++i) {
            for (int j=i+1; j<n; ++j) {
                ans+=m[nums[i]*nums[j]]++;
            }
        }
        return ans*8;
    }
};