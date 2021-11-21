/*
    operation1: swap any 2 existing chars to form same pattern
        It means we can transform to any order
    operation2: detect same pattern or not.
        Just check counting of each char. How?
    -----
    word1: "cabbba" -> aabbbc -> caabbb
    word2: "abbccc" -> abbccc
    T:O(n)/S:O(26)=O(1)
    -----
    Note that in op2, we can only Transform every occurrence existing character.
*/
class Solution {
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size()!=word2.size()) return false;
        vector<int> table1(26,0), table2(26,0);
        unordered_set<char> seen;
        for (char c:word1) {table1[c-'a']++; seen.insert(c);}
        for (char c:word2) {
            table2[c-'a']++;
            if (seen.count(c)!=0) seen.erase(c);
        }
        if (seen.size()!=0) return false;
        sort(table1.begin(),table1.end());
        sort(table2.begin(),table2.end());
        for (int i=0; i<26; ++i) {
            if (table1[i]!=table2[i]) return false;
        }
        return true;
    }
};
