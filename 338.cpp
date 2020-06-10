
class Solution {
// Dynamic programming, T:O(n), S:O(n)
/*

The basic logic is:
i -> i & i -1 modify the right-to-left first-met 1 to 0, thus reducing the number of ones by 1
X..X 1 0..0 -> X..X 0 0..0, where X means 0 or 1, X..X means any numbers of X (including zero X )

*/

public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};
