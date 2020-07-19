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
