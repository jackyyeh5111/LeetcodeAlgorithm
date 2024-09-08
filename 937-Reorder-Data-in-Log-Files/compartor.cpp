class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter_logs, digit_logs;
        for (const string &log : logs) {
            if (isDigitLog(log))
                digit_logs.push_back(log);
            else
                letter_logs.push_back(log);
        }
        
        // sort
        sortLetterLogs(letter_logs);
        
        vector<string> output = std::move(letter_logs);
        output.insert(output.end(), digit_logs.begin(), digit_logs.end());
        return output;
    }
    void sortLetterLogs(vector<string>& letter_logs) {
        auto comp = [](const string& s1, const string& s2) {
            int pos1 = s1.find(' ');
            int pos2 = s2.find(' ');

            string identifier1 = s1.substr(0, pos1);
            string identifier2 = s2.substr(0, pos2);

            string content1 = s1.substr(pos1+1);
            string content2 = s2.substr(pos2+1);
            return content1 == content2 ? identifier1 < identifier2 : content1 < content2;
        };
        sort(letter_logs.begin(), letter_logs.end(), comp);
    }

    bool isDigitLog(const string &log) {
        int pos = log.find(' ');
        char ch = log[pos+1];
        return ch >= '0' && ch <= '9';
    }
};

/* 
    letter_logs
    digit_logs
 */