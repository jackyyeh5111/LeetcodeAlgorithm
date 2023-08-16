/* 
    Fail case:
        dividend = 0
        divisor = 1
 */
class Solution2 {
public:
    int divide(int dividend, int divisor) {
        
        // special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool diff_sign = (abs(dividend) == dividend) ^ (abs(divisor) == divisor);
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        /* 
            value: 3, 3+3, 3+3+3+3
            quotient: 1, 2, 4
         */
        // check quotient range by exponential
        int quotient = 1; // 4
        int prev_quotient = 1; // 2
        int val = divisor; // 12
        int prev_val = divisor; // 6
        while (true) {
            if (dividend < val) // 
                break;
            
            prev_val = val;
            prev_quotient = quotient;
            
            // check 30th bit is 1 or not
            // std::cout << (1073741824 >> 31 & 1) << '\n';
            // std::cout << (1 << 31) << '\n';
            // std::cout << (1073741824 >> 30 & 1) << '\n';
            // std::cout << (1 << 30) << '\n';
            if (val >> 30 & 1)
                break;
            
            quotient += quotient;
            val += val; 
        }

        // check quotient one by one
        dividend -= prev_val; // 4
        quotient = prev_quotient; // 2
        while(dividend >= divisor) {
            quotient++;
            dividend -= divisor;
        }

        return diff_sign ? -quotient : quotient;
    }
};

/* 
    Fail case:
        dividend = 2147483647
        divisor = 1
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool diff_sign = (abs(dividend) == dividend) ^ (abs(divisor) == divisor);
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        /* 
            valge: 3, 3+3, 3+3+3+3
            quotient: 1, 2, 4
         */
        // check quotient range by power
        int quotient = 1;
        int prev_quotient = 1;
        int val = divisor;
        int prev_val = divisor;
        while (true) {
            if (dividend < val)
                break;
            prev_val = val;
            val += val; // this line may cause out of range!
            
            prev_quotient = quotient;
            quotient += quotient;
        }

        // check quotient one by one
        val = prev_val;
        quotient = prev_quotient;
        while(true) {
            if (dividend < val)
                break;
            val += divisor;
            quotient += 1;
        }

        return diff_sign ? -(quotient - 1) : quotient - 1;
    }
};

/* 
    clarification:
    1. sign may be different
    2. divisor != 0
 
    dividend: 3
    divisor: 3
    
    valge: 3, 3+3, 3+3+3+3
    quotient: 1, 2, 4
    bs
 */