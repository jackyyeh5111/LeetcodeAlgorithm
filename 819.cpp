class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // create banned hashset         
        unordered_set<string> banned_set(banned.begin(), banned.end());

        unordered_map<string, int> word_to_cnt;
        int start = 0, end = 0;
        while(end < paragraph.size()) {
            // keep going if char is alpha and not running into '\n'
            while(end < paragraph.size() && isAlpha(paragraph[end]))
                end++;
            int len = end - start;
            if (len > 0) {    
                string word = paragraph.substr(start, len);
                word = toLower(word);
                if (!banned_set.count(word))
                    word_to_cnt[word]++;
            }
            end++;
            start = end;
        }
        
        return getMostCommonWord(word_to_cnt);
    }
    string toLower(string word) {
        int offset = 'a' - 'A';
        for (int idx = 0; idx < word.size(); idx++) {
            if (word[idx] < 'a') word[idx] += offset;
        }
        return word;
    }
    string getMostCommonWord(const unordered_map<string, int> &word_to_cnt) {
        int max_freq = -1;
        string ans = "";
        for (const auto &pair : word_to_cnt) {
            if (pair.second > max_freq) {
                max_freq = pair.second;
                ans = pair.first;
            }
        }
        return ans;
    }
    bool isAlpha(const char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
};

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