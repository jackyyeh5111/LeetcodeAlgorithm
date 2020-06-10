#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (haystack.length() == 0 || needle.length() == 0)
            return 0;

        int index = -1;
        for(int i = 0; i < haystack.length() - needle.length(); ++i){
            int temp = 0;
            for (int j = 0; j < needle.length(); ++j){
                if (haystack[i+j] == needle[j])
                    temp++;
                else
                    break;
            }
            if (temp == needle.length()){
                index = i;
                break;
            }
        }
        return index;
    }
};
