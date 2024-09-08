/* 
    Visit2: use twp pointers with double while loop, making problem a lot easier.

    1. Check not leading zero
    2. Loop through string
    
    applbb...bbe
    a34e
       ^
     s  
 */

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        /* 
            word: a[b..b]cde
                         ^
            abbr: a21d1
                     ^
         */
        int ptr_w = 0, ptr_a = 0;
        while(ptr_w < word.size() && ptr_a < abbr.size()) {
            if (isdigit(abbr[ptr_a])) {
                // check leading zero
                if (abbr[ptr_a] == '0') return false;
                int start = ptr_a;
                while(ptr_a < abbr.size() && isdigit(abbr[ptr_a]))
                    ptr_a++;
                int num = stoi(abbr.substr(start, ptr_a - start));
                ptr_w += num; // skip
            }
            else {
                if (abbr[ptr_a] != word[ptr_w]) return false;
                ptr_a++;
                ptr_w++;
            }
        }
        return ptr_w == word.size() && ptr_a == abbr.size();
    }
};

class Solution {
public:
    /* 
         applbb...bbe
         ^   
        true_idx = 0 + 34 + 1
        skip = 34
        a34e
           ^
     */
    bool validWordAbbreviation(string word, string abbr) {
        /* 
            word: abcde
            abbr: a2d1
                     ^
         */
        
        int true_idx = 0; // 5
        int start = 0; // 1
        bool in_digit = false;
        for (int pos = 0; pos < abbr.size(); pos++) {
            char ch = abbr[pos];
            if (isdigit(ch)) {
                // check leading zero
                if (!in_digit && ch == '0') return false;
                if (!in_digit) {
                    start = pos;
                    in_digit = true;
                }
            }
            else {
                if (in_digit) {
                    string digit = abbr.substr(start, pos - start);
                    true_idx += stoi(digit);
                    if (true_idx >= word.size()) return false;
                    in_digit = false;
                }

                // compare char
                if (ch != word[true_idx]) return false;
                true_idx++;
            }
        }

        /* 
            edge case: digit is at the last idx of word
            word: abcde
            abbr: a2d1
                      ^
         */
        if (in_digit) {
            string digit = abbr.substr(start);
            true_idx += stoi(digit);
        }

        return true_idx == word.size();
    }
};

/* 
    1. Check not leading zero
    2. Loop through string
    
    applbb...bbe
    ^
    
    true_idx = 0 + 34 + 1
    skip = 34
    a34e
       ^
     s  
 */