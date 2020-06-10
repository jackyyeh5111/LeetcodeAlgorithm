class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x<0) return false;
        long invert_x = 0;
        long input_x = (long)x;
        while (x!=0) {
            invert_x = invert_x*10+x%10;
            x/=10;
        }
        return input_x==invert_x;

    }

    // Optima solution to avoid INT_MAX
    // bool isPalindrome(int x)
    // {
    //     if (x<0) return false;
    //     int invert_x = 0;
    //     while (x>invert_x) {
    //         invert_x = invert_x*10+x%10;
    //         x/=10;
    //     }
    //
    //     // divide 10 if odd palindrom
    //     return x == invert_x || x == invert_x/10;
    //
    // }
};
