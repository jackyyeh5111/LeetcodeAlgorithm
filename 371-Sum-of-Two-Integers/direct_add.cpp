class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            int XOR = a ^ b;
            int carry = (a & b) << 1;
            a = XOR;
            b = carry;
        }
        return a;
    }
};

/* 
    case: a, b same sign
        i = 1
            a: 011
            b: 001
          xor: 010
        carry: 010 
              
        i = 2
            a: 111 (-1)
            b: 100
          xor: 011
        carry: 100 
              1000
        
        bit = bita XOR bitb XOR carry
        carry = (bita & bitb) << 1

    case a, b different sign (abs(a) > abs(b))

        a:  110 (-2)
        b:  001 (1)
      xor:  111
    carry:  000
        
        s:  111 (-1)
        
    case a < 0, b >= 0:

        a:  111 (-1)
        b:  010 (2)
        s:  001 (1)


    Process:


    Clarification:
    1. -1000 <= a, b <= 1000
 */