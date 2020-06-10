#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        std::vector<int>::iterator it;
        int count = 0;
        for (it=nums.begin(); it!=nums.end();){
            if(*it == val)
                it = nums.erase(it);
            else{
                it++;
                count++;
            }
        }

        return count;
    }
};
