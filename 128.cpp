class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        /*
        despite looking like O(n \cdot n)O(n⋅n) complexity, the nested loops
        actually run in O(n + n) = O(n)O(n+n)=O(n) time. All other computations
        occur in constant time, so the overall runtime is linear.

        Just keep in mind use UNION(set) to reduce searching complexity to O(1)
        */
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for (int num:nums) {
            if(s.find(num-1)==s.end()&&num!=INT_MAX) {
                int tmp=1; num++;
                while(num!=INT_MAX&&s.find(num++)!=s.end()) tmp++;
                ans=max(ans,tmp);
            }
        }
        return ans;
    }
};
