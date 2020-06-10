import java.lang.*;

class Solution {
    public int myAtoi(String str) {
        long result = 0;
        int sign = 1;
        for (int i = 0; i < str.length(); ++i){
            if (str.charAt(i) == ' ')
                continue;

            if(str.charAt(i) == '-'){
                sign = -1;
                ++i;
            }
            else if(str.charAt(i) == '+'){
                sign = 1;
                ++i;
            }

            while (i < str.length() && '0'<=str.charAt(i) && str.charAt(i) <= '9'){
                result = result * 10 + (str.charAt(i) - '0');
                if (result*sign >= Integer.MAX_VALUE) return Integer.MAX_VALUE;
                if (result*sign <=  Integer.MIN_VALUE) return Integer.MIN_VALUE;
                i++;
            }
            break;
        }
        result = sign*result;

        return (int)result;
    }
}
