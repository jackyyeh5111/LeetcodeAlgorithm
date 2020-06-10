class Solution {
public:
    int divide(int dividend, int divisor)
    {
        // T:O(logN * logN)
        int quotation = 0;
        if (dividend==INT_MIN&&divisor==-1) return INT_MAX;
        else if (dividend==INT_MIN&&divisor==1) return INT_MIN;
        else if(dividend==INT_MIN) {
            if (divisor==INT_MIN) return 1;
            dividend+=abs(divisor);
            quotation += 1;
        }
        else if (divisor==INT_MIN) return 0;


        bool sign = (dividend^divisor) & (1<<31);
        dividend = abs(dividend); divisor = abs(divisor);
        while(dividend>=divisor){ // O(logN)
            int tmp = divisor; int count = 1;
            while(dividend - tmp >= tmp) { // O(logN)
                tmp = tmp<<1;
                count = count<<1;
            }
            quotation += count;
            dividend -= tmp;
        }

        return sign ? -1^(quotation-1) : quotation;

    }
};
