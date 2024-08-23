/* 
    k = 4
    XXXXXXX P

    XXXX P XXX
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k, 0, nums.size()-1);
    }
    int quickSelect(vector<int>& nums, int k, int low, int high) {
        if (low >= high)
            return nums[low];
        
        int pivot = nums[high];
        int pi_idx = low;
        for (int i = low; i <= high - 1; i++) {
            if (nums[i] < pivot) {
                swap(nums[pi_idx], nums[i]);
                pi_idx++;
            }
        }
        swap(nums[pi_idx], nums[high]);

        int num_largest_found = high - pi_idx + 1;
        if (k == num_largest_found)
            return nums[pi_idx];
        else if (k < num_largest_found)
            return quickSelect(nums, k, pi_idx + 1, high);
        else
            return quickSelect(nums, k - num_largest_found, low, pi_idx - 1);
    }
};
