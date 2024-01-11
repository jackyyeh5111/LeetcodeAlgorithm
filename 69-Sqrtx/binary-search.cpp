/* 
    Slightly adjust the thought.
    Then we do not have to check the return value.
 */
class Solution3 {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int left = 1, right = x / 2;
        while(left < right) { // left: 2, right: 2
            int mid = right - (right - left) / 2; // change here
            int temp = x / mid; // 2
            if (mid == temp)
                return mid;
            if (mid < temp)
                left = mid;
            else 
                right = mid - 1;
        }
        return left;
    }
};

class Solution2 {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        int left = 1, right = x / 2;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (mid > x / mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left > x / left ? left - 1 : left;
    }
};

/* 
    wrong answer

    fail case:
        2147395599
 */
class Solution {
public:
    int mySqrt(int x) {
        if (x == 1)
            return 1;
        int left = 0, right = x / 2;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (mid * mid <= x && x < (mid+1) * (mid+1)) // overflow here
                return mid;
            if (mid * mid > x)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

/* 
    a = mySqrt(x)
    
    1. a^2 <= x < (a+1)^2
    2. a <= x/2

    Find a between 0 ~ x/2
 */