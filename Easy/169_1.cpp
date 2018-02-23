#include <unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        std::unordered_map<int, int> countMap;
        int maxValue = nums[0];

        for (int val : nums){
            countMap[val]++;

            if (countMap[val] > countMap[maxValue])
                maxValue = val;
            else if (countMap[val] > nums.size() / 2){
                maxValue = val;
                break;
            }
        }

        return maxValue;
    }
};
