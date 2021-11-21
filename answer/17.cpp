/***** Fourth Visit *****/
/*
    T:O(4^n)/S:O(4^n)
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> table={{1,""},{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        if (digits==""||digits=="1") return {};

        queue<string> q; q.push("");
        for (char d:digits) {
            int k=q.size();
            while (k--) {
                string t=q.front(); q.pop();
                for (char c:table[d-'0']) {
                    q.push(t+string(1,c));
                }
            }
        }
        vector<string> ans;
        while (!q.empty()) {ans.push_back(q.front()); q.pop();}
        return ans;

    }
};

/***** Third Visit *****/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) return {};
        unordered_map<char, string> table{{'2',"abc"},{'3',"def"},{'4',"ghi"},
                                          {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
                                          {'8',"tuv"}, {'9',"wxyz"}};
        vector<string> ans;
        int idx=0;
        dfs(table,digits,idx,"",ans);
        return ans;
    }

    void dfs(unordered_map<char, string> &table, string digits, int idx, string cur, vector<string> &ans)
    {
        if (idx==digits.size()) {
            ans.push_back(cur);
            return;
        }
        for (char c:table[digits[idx]])
            dfs(table,digits,idx+1,cur+c,ans);
    }
};

/***** Second Visit *****/
/*
    iterative
    T:O(4^n)/S:O(4^n)
    ------
    Recursive
    T:O(4^n)/S:O(4^n)
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static unordered_map<char, string> table{
            {'2',"abc"},{'3',"def"},{'4',"ghi"},
            {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
            {'8',"tuv"}, {'9',"wxyz"}};
        vector<string> ans;
        for (char c:digits) {
            int n=ans.size();
            for (char t:table[c]){
                if (n==0) ans.push_back(string(1,t));
                else {
                    for (int i=0; i<n; ++i) {
                        ans.push_back(ans[i]+t);
                    }
                }
            }
            ans.erase(ans.begin(),ans.begin()+n);
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    // T: O(3^N + 4^N), S: O(3^N + 4^N)
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> table{{'2',"abc"},{'3',"def"},{'4',"ghi"},
                                          {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
                                          {'8',"tuv"}, {'9',"wxyz"}};

        vector<string> ans;
        for (char digit : digits) {
            if (ans.size()==0) {
                for (char letter : table[digit])
                    ans.push_back(string(1, letter));
            }
            else {
                int nums = ans.size();
                for (char letter : table[digit]) {
                    for (int i=0; i<nums; ++i) {
                        ans.push_back(ans[i]+string(1, letter));
                    }
                }
                ans.erase(ans.begin(), ans.begin()+nums);
            }
        }
        return ans;
    }
};
