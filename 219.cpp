class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        /*
            use a hashmap to record latest appearance index.
            T:O(n) with one pass, S:O(n)
            ---
            Another thought: use unordered_set to keep latest k elements
        */
        unordered_map<int,int> m;
        int size=nums.size();
        for (int i=0; i<size; ++i) {
            int num=nums[i];
            if (m.find(num)!=m.end() && i-m[num]<=k) return true;
            m[num]=i;
        }
        return false;
    }
};
