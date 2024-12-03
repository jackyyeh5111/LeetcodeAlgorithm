class Solution {
public:
    int romanToInt(string s) {
        const unordered_map<char, int> char_to_int {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        /* 
            IV
         */
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (i < s.size() - 1) {
                char next_ch = s[i+1];
                if (char_to_int.at(next_ch) > char_to_int.at(ch)) {
                    int num = char_to_int.at(next_ch) - char_to_int.at(ch);
                    sum += num;
                    i++;
                    continue;
                }
            }
            sum += char_to_int.at(ch);
        }
        return sum;
    }
};

/* 
    largest to smallest
    XII -> 12
    XIV -> 14
 */