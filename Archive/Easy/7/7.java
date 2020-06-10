import java.util.*;
import java.lang.Integer;
import java.lang.Math;

class Solution {
    public int reverse(int x)
    {
        int reverseNumber = 0;
        while (x > 0){
            if (Math.abs(reverseNumber) > Integer.MAX_VALUE / 10)
                return 0;
            reverseNumber = reverseNumber * 10 + x % 10;
            x /= 10;
        }

        return reverseNumber;
    }
}
