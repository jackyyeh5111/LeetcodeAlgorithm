/* 
    Correct answer, although leetcode shows this goes time limit excess.

    Testcase that does not match time condition:
        x: 2.00000
        n: -2147483648    
    But x^n < 10^4 is declared in constraints.
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1)
            return 1;
        bool n_sign = n > 0;
        if (n > 0)
            n = -n;
        int power = 1;
        int log_n = n;
        double val = x;
        // Step 1: double power value repetitively
        while(true) {
            log_n = log_n / 2;
            if (log_n == 0)
                break;
            val = val * val;
            power = power * 2;
        }

        // Step 2: Increase power value one by one
        while (-power > n) {
            val = val * x;
            power = power + 1;
        }

        if (!n_sign)
            val = 1 / val;
        return val;
    }
};

/* 
    Wrong answer

    x: 2.00000
    n: -2147483648
 */
class Solution2 {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        
        bool n_sign = n > 0;
        n = abs(n); // wrong here. abs(-2147483648) = -2147483648
        int power = 1;
        int log_n = 1;
        double val = x;
        // Step 1: double power value repetitively
        while(true) {
            log_n = log_n / 2;
            if (log_n == 0)
                break;
            val = val * val;
            power = power * 2;
        }

        // Step 2: Increase power value one by one
        while (power < n) {
            val = val * x;
            power = power + 1;
        }

        if (!n_sign)
            val = 1 / val;
        return val;
    }
};

/* 
    case 1: n > 0

        x: 2.0
        n: 10

        myPow {
            Step 1: double power value repetitively
                x     power             n     
                2.0       1             10    8   
                4.0       2             5     4 
                16.0      4             2     1 
                256.0.    8. <-----     1     0      
                2^16      16            0       
                
                when x > n, we get the previous power

            Step 2: Increase power value one by one
        }
    
    case 2: n < 0
        val = myPow()
        return 1 / val;
 */

/* 
    Wrong answer
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        
        bool n_sign = n > 0;
        n = abs(n);
        int power = 1;
        double val = x;
        double prev_val;
        // Step 1: double power value repetitively
        while(power <= n) {
            prev_val = val;
            val = val * val;
            power = power * 2; // overflow here
        }

        // Step 2: Increase power value one by one
        power = power / 2; // rollback 1
        val = prev_val; // rollback 1
        while (power < n) {
            val = val * x;
            power = power + 1;
        }

        if (!n_sign)
            val = 1 / val;
        return val;
    }
};

/* 
    case 1: n > 0

        x: 2.0
        n: 10

        myPow {
            Step 1: double power value repetitively
                x     power
                2.0       1   
                4.0       2   
                16.0      4
                256.0.    8. <-----
                2^16      16
                
                when x > n, we get the previous power

            Step 2: Increase power value one by one
        }
    
    case 2: n < 0
        val = myPow()
        return 1 / val;
 */