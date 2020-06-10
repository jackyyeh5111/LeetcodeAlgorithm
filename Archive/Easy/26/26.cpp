#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        std::vector<int>::iterator iter;
        int current_value = nums[0], count = 1;
        for(iter = nums.begin(); iter != nums.end(); ++iter){
            if (*iter != current_value){
                current_value = *iter;
                nums[count] = current_value;
                ++count;
            }
        }

        return count;
    }
};
