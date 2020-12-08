/***** Second Visit *****/
/*
    5! = 1x2x3x4x5
           ^     ^ -> 1
    10! = 1x2x3x4x5x6x7x8x9x10
            ^     ^         ^ -> 2
    20! = 1x...x10x11x12x13x14x15x16x17x18x19x20
    -----
    Constraint: T:O(logn)
    Reduce the problem to counting 5.
    ans = n/5 + n/25 + n/125 + ... until n/5^k is equal to 0.
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        while (n/5) {
            ans+=n/5;
            n/=5;
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    int trailingZeroes(int n)
    {
        /*
            brute force: O(n), calculate and count trailing 0.
            cons: Easy to meet integer overflow.
            --------------------
            Count how many 5 we have in the factorial
            5 10 15 20 25 30 35 40 45 50
            1 1  1  1  2  1  1  1  1  2
            1 2  3  4  6  7  8  9  10 12
        */
        int count=0;
        while(n/5){
            count+=n/5;
            n=n/5;
        }
        return count;

    }
};
