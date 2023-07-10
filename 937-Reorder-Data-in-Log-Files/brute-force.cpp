class Solution {
public:

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter_logs, digit_logs;
        for (string log : logs) {
            char ch = log.substr(log.find(' ') + 1)[0];
            if (ch >= 'a' && ch <= 'z')
                letter_logs.push_back(log);
            else
                digit_logs.push_back(log);
        }

        // customized compare
        auto comp = [](const string &s1, const string &s2) {
            string subs1 = s1.substr(s1.find(' ') + 1);
            string subs2 = s2.substr(s2.find(' ') + 1);

            return subs1 != subs2 ? subs1 < subs2 : s1 < s2;
        };

        sort(letter_logs.begin(), letter_logs.end(), comp);
        letter_logs.insert(letter_logs.end(), digit_logs.begin(), digit_logs.end());
        return letter_logs;
    }
};

/* 
    s1 > s2 => true (s1 is lexicalgraphically larger than s2)

    letter_logs :[
        "let1 art can",
        "let2 own kit dig",
        "let3 art zero"
        "let2 art zero"
    ]
        => (sort)
    letter_logs :[
        "let1 art can",
        "let2 art zero",
        "let3 art zero"
        "let2 own kit dig",
    ]
        
    digit_logs : [
        "dig1 8 1 5 1",
        "dig2 3 6"
    ]
 */