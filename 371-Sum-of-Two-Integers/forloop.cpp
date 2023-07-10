/* 
    如果不想要用 for loop 寫死 N = 32，換成 while 迴圈如何寫？
    
    ERROR:
    Line 33: Char 22: runtime error: shift exponent 32 is too large for 32-bit type 'int' (solution.cpp)
    SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:42:22
 */
/* 
    bita, bitb carry | bit, next_carry
    0, 0, 0 | 0, 0
    1, 0, 0 | 1, 0
    1, 1, 0 | 0, 1
    ...
 */
class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int pos = 0;
        int carry = 0;
        while (a != 0 || b != 0) {
            int bita = a >> pos & 1;
            int bitb = b >> pos & 1;
            int total = bita + bitb + carry;
            if (total == 1) {
                ans |= 1 << pos;
                carry = 0;
            }
            else if (total == 2) {
                carry = 1;
            }
            else if (total == 3) {
                ans |= 1 << pos;
                carry = 1;
            }
            a = a ^ (bita << pos);
            b = b ^ (bitb << pos);
            ++pos;
        }
        ans |= carry << pos; // go wrong here.
        return ans;
    }
};

/* 
    a b carry           carry 
    1 1   1.  ==> 1       1
    1 0   1.  ==> 0       1
    0 1   1.  ==> 0       1
    0 0   1.  ==> 1       0
    
    1 1   0.  ==> 0       1
    1 0   0.  ==> 1       0
    0 1   0.  ==> 1       0
    0 0   0.  ==> 0       0
 */
class Solution {
public:
    int getSum(int a, int b) {
        const int N = 32;
        int ans = 0, carry = 0;
        for (int i = 0; i < N; ++i) 
        {
            bool bita = a >> i & 1;
            bool bitb = b >> i & 1;
            int sum = bita + bitb + carry;
            if (sum == 1) 
            {
                ans |= 1 << i;
                carry = 0;
            }
            else if (sum == 2) 
            {
                carry = 1;
            }
            else if (sum == 3) 
            {
                ans |= 1 << i;
                carry = 1;
            }
        }
        return ans;
    }
};
