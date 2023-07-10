/* 
    Check if the element is the starting num of the sequence.
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int ans = 0;
        for (auto num : nums) {
            if (us.find(num - 1) != us.end())
                continue;
            int cnt = 1;
            while(us.find(num + 1) != us.end()) {
                ++num;
                ++cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
