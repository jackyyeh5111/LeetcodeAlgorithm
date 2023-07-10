class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (true) {
            if (n == 0) break;
            n = n & (n-1);
            ++cnt;
        }
        return cnt;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n != 0) {
            n -= (n & -n);
            ++cnt;
        }
        return cnt;

    }
};