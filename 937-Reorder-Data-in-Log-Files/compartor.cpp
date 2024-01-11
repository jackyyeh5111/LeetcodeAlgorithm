/* 
    Be careful to use stable sort!
 */
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto comp = [](const string &s1, const string &s2) {
            int pos1 = s1.find(' ');
            int pos2 = s2.find(' ');
            char ch1 = s1[pos1 + 1];
            char ch2 = s2[pos2 + 1];
            bool is_digit1 = ch1 >= '0' && ch1 <= '9';
            bool is_digit2 = ch2 >= '0' && ch2 <= '9';
            if (is_digit1 && is_digit2)
                return false; // <----
            if (!is_digit1 && is_digit2)
                return true;
            if (is_digit1 && !is_digit2)
                return false;
            
            // both of strings are letter logs
            string substr1 = s1.substr(pos1 + 1);
            string substr2 = s2.substr(pos2 + 1);
            return substr1 == substr2 ? s1 < s2 : substr1 < substr2;
        };
        stable_sort(logs.begin(), logs.end(), comp);
        return logs;
    }
};

