#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s)
    {
        std::unordered_map<char, int> dictionary;
        dictionary['I']= 1    ;
        dictionary['V']= 5    ;
        dictionary['X']= 10   ;
        dictionary['L']= 50   ;
        dictionary['C']= 100  ;
        dictionary['D']= 500  ;
        dictionary['M']= 1000 ;

        int result = 0;
        for (int idx = 0; idx < s.length() - 1; ++idx){
            if (dictionary[s[idx]] < dictionary[s[idx + 1]])
                result -= dictionary[s[idx]];
            else
                result += dictionary[s[idx]];
        }
        result += dictionary[s[s.length() - 1]];

        return result;
    }
};
