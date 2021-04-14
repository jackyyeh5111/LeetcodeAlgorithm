/*
    "abpcplea", d = ["ale","apple","monkey","plea"]
    a 0 7
    b 1
    c 3
    e 6
    l 5
    p 2 4

    binary search index on each char (increasing order)
    T:O(n+kmlogn)
*/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d)
    {
        vector<vector<int>> table(26,vector<int>{});
        for (int i=0; i<s.length(); ++i) table[s[i]-'a'].push_back(i);
        int ans=-1;
        for (int i=0; i<d.size(); ++i) {
            string word=d[i];
            int p=-1, idx=0;
            for (; idx<word.size(); ++idx) {
                auto it=upper_bound(table[word[idx]-'a'].begin(),table[word[idx]-'a'].end(),p);
                if (it!=table[word[idx]-'a'].end()) p=*it;
                else break;
            }
            if (idx==word.size()&&
                (ans==-1||word.size()>d[ans].size()||word.size()==d[ans].size()&&word<d[ans])) ans=i;
        }
        return ans==-1?"":d[ans];
    }
};
