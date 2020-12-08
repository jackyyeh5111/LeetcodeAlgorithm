/***** Second Visit *****/
/*
    1. INT_MAX/INT_MIN edge case handling
    2. TLE due to O(dividend/divisor), use exponential checking O(log(dividend)) instead.

*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg=(dividend>=0)^(divisor>=0);
        int ans=0;
        if (dividend==INT_MIN&&divisor==INT_MIN) return 1;
        else if (divisor==INT_MIN) return 0;
        else if (dividend==INT_MIN&&divisor==-1) return INT_MAX;
        else if (dividend==INT_MIN&&divisor==1) return INT_MIN;
        else if (dividend==INT_MIN) {
            dividend+=abs(divisor);
            ans++;
        }
        dividend=abs(dividend);
        divisor=abs(divisor);
        while(dividend>=divisor) {
            int tmp=divisor, tmp_c=1;
            while(dividend-tmp>=tmp){
                tmp=tmp<<1;
                tmp_c=tmp_c<<1;
            }
            ans+=tmp_c;
            dividend-=tmp;
        }
        return neg?-1*ans:ans;
    }
};

/***** First Visit *****/
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
