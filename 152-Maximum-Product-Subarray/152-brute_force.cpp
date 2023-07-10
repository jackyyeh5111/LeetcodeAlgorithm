/* 
    (這是自己寫出來的歐！)    

   positive, negative, 0

    在沒有零的情況下：
        XXXX -1 X -2 XX -3 XXX

        1. without zero, all positive ==> maxProduct(nums[1:N])
        2. without zero, even negative ==> maxProduct(nums[1:N])
        3. without zero, odd negative ==> maxProduct(max(nums[1:right-1], nums[left+1:N]))
   
    再有零的情況下：
        先把數組用零切成好幾段(每一段都可以保證沒有零)，接著就可以用沒有零的三種情況處理

        XXX 0 XXX 0 XXXX
            L1.   L2
        
        with zero, maxProduct(0, nums[1:L1-1], nums[L1+1:L2-1], nums[L2+1:...], ...)
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) return nums[0];
        vector<vector<int>> mems; // [start, end, product] 切斷的數組起始點、結束點、乘積
        int start = 0;
        for (start=0; start < N; start++) { // skip leading zeros
            if (nums[start] != 0)
                break;
        }

        /* 
            ex: [2,3,0,4]    
                mems = [
                    [0, 1, 6],
                    [3, 3, 4]
                ]
         */
        int product = 1;
        for (int i = start; i < N; i++) {
            if (nums[i] == 0) {
                mems.push_back({start, i - 1, product});
                start = i + 1;
                product = 1;
            }
            else {
                product *= nums[i];
            }
        }
        if (start != N)
            mems.push_back({start, N - 1, product});

        // process products that are negative
        int ans = 0;
        for (auto mem : mems) {
            ans = max(ans, maxProduct(nums, mem[0], mem[1], mem[2]));
        }
        return ans;
    }
    int maxProduct( const vector<int>& nums, int start, int end, int product) {
        if (start == end) return nums[start];
        if (product > 0) return product;
        
        // if (product < 0)
        int left_product = 1;
        for (int i = start; i <= end; i++) {
            left_product *= nums[i];
            if (nums[i] < 0)
                break;
        }
        int right_product = 1;
        for (int i = end; i >= start; i--) {
            right_product *= nums[i];
            if (nums[i] < 0)
                break;
        }
        return max(product / left_product, product / right_product);
    }
};
