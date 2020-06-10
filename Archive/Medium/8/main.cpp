#include <iostream>
#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string str) {
        long result = 0;
        int sign = 1;
        for (int i = 0; i < str.length(); ++i){
            if (str[i] == ' ')
                continue;

            if(str[i] == '-'){
                sign = -1;
                ++i;
            }
            else if(str[i] == '+'){
                sign = 1;
                ++i;
            }

            while ('0'<=str[i] && str[i] <= '9'){
                result = result * 10 + (str[i] - '0');
                if (result*sign >= INT_MAX) return INT_MAX;
                if (result*sign <=  INT_MIN) return INT_MIN;
                i++;
            }
            break;
        }
        result = sign*result;

        return result;
    }
};

