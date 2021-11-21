/********* math proof *********/
/*
    (4^n - 1) % 3 == 0
    another proof:
    (1) 4^n - 1 = (2^n + 1) * (2^n - 1)
    (2) among any 3 consecutive numbers, there must be a multiple of 3
    among (2^n-1), (2^n), (2^n+1), one of them must be a multiple of 3, and
    (2^n) cannot be the one, therefore either (2^n-1) or (2^n+1) must be a 
    multiple of 3, and 4^n-1 must be a multiple of 3 as well.
*/
class Solution {
public:
    bool isPowerOfFour(int num)
    {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};

/********* bit manipulation *********/
class Solution {
public:
    bool isPowerOfFour(int num)
    {
        /*
            0x0x0x0x 0x0x0x0x 0x0x0x0x 0x0x0x0x
            0x55555555
        */
        if (num<0) return false;
        int bits = num & 0xaaaaaaaa;
        if (num==0||bits!=0) return false;
        else return (num&(num-1))==0;
    }
};
