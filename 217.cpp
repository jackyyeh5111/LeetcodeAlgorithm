class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> m;
        for (int num:nums) {
            if(m.find(num)!=m.end()) return true;
            m.insert(num);
        }
        return false;
    }
};
