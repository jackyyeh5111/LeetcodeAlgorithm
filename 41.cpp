// Reduced to Correct Slot Filling
class Solution {
public:
    //T: O(2n), S:O(1)
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;

    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        // T:O(n), S:O(n)
        int min_positive = INT_MAX;
        unordered_set<int> table;
        for (int& num:nums) { //T:O(n)
            if (num>0&&num<min_positive) min_positive = num;
            if (num>0) table.insert(num);
        }
        if (min_positive==INT_MAX||min_positive!=1) return 1;
        int i=2;
        while (i<=table.size()) { //T:O(n)
            if (table.find(i)==table.end()) return i; //T:O(1)
            i++;
        }
        return i;
    }
};
