class Solution {
public:
    int getSum(int a, int b) {
        int x = abs(a), y = abs(b);
        if (x < y)
            return getSum(b, a);
        
        // cannot handle the case when either a or b equals to 0.
        // int sign = a * b > 0  ? 1 : -1;
        int sign = a > 0 ? 1 : -1;
            
        int answer, carry, borrow;
        if (a * b >= 0) {
            while (y) {
                answer = x ^ y;
                carry = (x & y) << 1;
                x = answer;
                y = carry;
            }
        }
        else { // sign == -1
            while (y) {
                answer = x ^ y;
                borrow = (~x & y) << 1;
                x = answer;
                y = borrow;
            }
        }
        return answer * sign;
    }
};