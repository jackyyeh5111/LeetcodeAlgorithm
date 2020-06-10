#include <string>
#include <iostream>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 0 || numRows == 1 || s.length() == 0 || s.length() == 1)
            return s;
        std::string result = "";
        for (int i = 0; i < numRows; ++i){
            for ( int j =i; j < s.length(); j += 2*numRows-2){
                result += s[j];
                if (i != 0 && i != numRows-1 && (j + 2*numRows-2-2*i)<s.length())
                    result += s[j + 2*numRows-2-2*i];
            }
        }
        return result;
    }
};
