class Solution {
    public int removeDuplicates(int[] nums) {
        int length = nums.length;
        if (length == 0)
            return 0;
        int count = 0;
        for (int idx = 1; idx < length; ++idx){
            if (nums[idx] != nums[count]){
                ++count;
                nums[count] = nums[idx];
            }
        }

        return count + 1;
    }
}
