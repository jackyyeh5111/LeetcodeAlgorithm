class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int count = 1;
        int major = nums[0];

        for (int i = 1; i < nums.size(); ++i){
            if (count == 0){
                count = 1;
                major = nums[i];
            }
            else if (major == nums[i])
                count++;
            else
                count--;
        }

        // check if major exists more than n/2, however we can assume it always exists as mentioned in title.
        return major;
    }
};
