/***** Third Visit *****/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string,vector<string>> mp;
        for (string str:strs) {
            string sorted=str;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it=mp.begin(); it!=mp.end(); ++it) {
            ans.push_back(it->second);
        }
        return ans;
    }
};

/***** Second Visit *****/
/*
    use a hashmap, k: SORTED word, v: vector<string> of original words
    T:2 pass O(n * klogk)/S:O(n)
    -----
    The problem is how to represent the anagram of str.
    SORT:
        1. quick sort T:(klogk)
        2. counting sort with size 26 T:O(k)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string,vector<string>> m;
        for (auto str:strs) {
            string sort_str=str;
            sort(sort_str.begin(),sort_str.end());
            if (m.find(sort_str)==m.end())
                m[sort_str]=vector<string>{};
            m[sort_str].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it=m.begin(); it!=m.end(); ++it) {
            ans.push_back(it->second);
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        // brute force
        // T:O(NM), n words with m length
        unordered_map<string, vector<string>> table;
        for (string& str:strs) {
            string represent=string(26,'0');
            for (char& c:str){
                represent[c-'a'] = (char)((int)represent[c-'a']+1);
            }
            table[represent].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it=table.begin(); it !=table.end(); ++it){
            ans.push_back(it->second);
        }
        return ans;
    }
};
