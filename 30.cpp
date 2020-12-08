/***** Second Visit *****/
/*
    unordered map comparison
    T:O(nk)/S:O(mk)
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> ans;
        unordered_map<string,int> table;
        for (auto word:words) table[word]++;
        int n=s.length(),m=words.size(),k=words[0].length();
        for (int i=0; i<n-m*k+1; ++i) {
            string sub=s.substr(i,m*k);
            unordered_map<string,int> seen;
            for (int j=0; j<m; ++j) {
                string subword=sub.substr(j*k,k);
                seen[subword]++;
            }
            if (seen==table) ans.push_back(i);
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    // T:O(M*N*k), S:O(N)
    vector<int> findSubstring(string s, vector<string>& words)
    {
        if(s=="" || words.size()==0) return vector<int>{};
        unordered_map<string, int> table;
        for (int i=0; i<words.size(); ++i) {
            table[words[i]]++; //default 0 if not found.
        }
        int word_num = words.size();
        int word_length = words[0].length();
        vector<int> ans;
        for (int i=0; i<s.length()-word_num*word_length+1; ++i) {
            unordered_map<string, int> seen;
            for (int j=0; j<word_num*word_length; j+=word_length) {
                string subword = s.substr(i+j,word_length);
                if (table.find(subword)!=table.end())
                    seen[subword]++;
            }
            if (seen==table)
                ans.push_back(i);
        }
        return ans;
    }
};

/*
Applying early stop and use counter to check if meet frequency table or not.
It is faster than comparing frequency table in each position all the way.
*/
class Solution {
public:
    // T:O(N*k), S:O(M)
    vector<int> findSubstring(string s, vector<string>& words)
    {
        if(s=="" || words.size()==0) return vector<int>{};
        unordered_map<string, int> table;
        for (int i=0; i<words.size(); ++i) {
            table[words[i]]++; //default 0 if not found.
        }
        int size = words[0].size();
        int window = size * words.size();
        vector<int> ans;
        for (int i = 0; i < size; ++i) {
            int start = i;
            while (start + window <= s.length()) {
                string sub = s.substr(start, window);
                unordered_map<string, int> seen;
                int j = words.size();
                while (j > 0) {
                    string word = sub.substr(size * (j - 1), size);
                    int count = seen[word] + 1;
                    if (count > table[word]) break;
                    seen[word]=count;
                    --j;
                }
                if (j == 0) {
                    ans.push_back(start);
                }
                start += size * max(j, 1);
            }
        }
        return ans;
    }
};
