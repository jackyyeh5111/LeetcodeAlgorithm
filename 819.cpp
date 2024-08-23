class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // 1) convert banned into hashset
        unordered_set<string> banned_set(banned.begin(), banned.end());
        
        // 1) create freq hashmap
        unordered_map<string, int> freq;
        string str = "";
        for (char ch : paragraph) {
            // delimiter
            if (!isValidChar(ch) && str.size() > 0) {
                if (!banned_set.count(str))
                    freq[str]++;
                str = ""; // reset
            }
            else {
                if (isValidChar(ch)) str += tolower(ch);
            }
        }

        // handle last string
        if (str.size() > 0 && !banned_set.count(str))
            freq[str]++;

        // 2) check string freq and remove banned string
        string output;
        int max_occur = 0;
        for (const auto &pair : freq) {
            if (pair.second > max_occur) {
                max_occur = pair.second;
                output = pair.first;
            }
        }
        return output;
    }
    char tolower(char ch) {
        if (ch >= 'A' && ch <= 'Z')
            return ch + 'a' - 'A';
        return ch;
    }
    bool isValidChar(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
};