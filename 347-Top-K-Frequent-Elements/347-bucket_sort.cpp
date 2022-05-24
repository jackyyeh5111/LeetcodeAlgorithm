#include "../utils.hpp"

/* approach 2: bucket sort
  Time: O(n)
*/
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        std::unordered_map<int, int> map;
        for (int num : nums)
            map[num]++;

        vector<vector<int>> bucket(nums.size());
        for (auto it = map.begin(); it != map.end(); it++) {
            bucket[it->second].push_back(it->first);
        }

        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (ans.size() >= k)
                break;
            ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
        }

        return ans;
    }
};