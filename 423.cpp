// observe numbers to find distinct char
class Solution {
public:
    string originalDigits(string s) {
        vector<string> words = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        vector<int> distinct_char = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
        vector<int> counts(26, 0);
        string result;
        for(auto ch : s){ counts[ch-'a']++;}
        for(int i = 0; i < 10; i++){
            int count = counts[distinct_char[i]-'a'];
            for(int j = 0; j < words[i].size(); j++)
                counts[words[i][j]-'a'] -= count;
            while(count--)
                result += to_string(nums[i]);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

// backtracking
/*
    1. construct cnt table.
    2. backtracking to findout digits in english
    3. sort the digits
*/
class Solution {
public:
    vector<string> words={"zero","one","two","three","four","five","six","seven","eight","nine"};
    unordered_map<string,int> mp={{"zero",0},{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9}};
    string originalDigits(string s)
    {
        vector<int> table(26,0);
        for (char c:s) table[c-'a']++;
        vector<pair<string,vector<int>>> digits;
        for (string &word:words) {
            vector<int> t(26,0);
            for (char &c:word) t[c-'a']++;
            digits.push_back({word,t});
        }
        string ans="";
        dfs(table,(int)s.length(),digits,0,ans);
        sort(ans.begin(),ans.end());

        return ans;

    }

    bool dfs(vector<int> table, int cnt, vector<pair<string,vector<int>>> &digits, int idx,
             string &ans)
    {
        if (idx>=10) return cnt==0;
        bool valid=true;
        for (int i=0; i<26; ++i) {
            table[i]-=digits[idx].second[i];
            if (table[i]<0) valid=false;
        }
        if (valid) {
            ans+=('0'+mp[digits[idx].first]);
            if (dfs(table, cnt-digits[idx].first.length(),digits,idx,ans)) return 1;
            ans.pop_back();
        }
        for (int i=0; i<26; ++i) {
            table[i]+=digits[idx].second[i];
        }
        return dfs(table,cnt,digits,idx+1,ans);
    }
};
