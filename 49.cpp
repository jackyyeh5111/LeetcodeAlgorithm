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
