class Solution {
public:
    int numDifferentIntegers(string word)
    {
        unordered_set<string> s;
        string cur="";
        int n=word.length();
        for (int i=0; i<n; ++i) {
            if (!isdigit(word[i])) {
                if (i>0&&isdigit(word[i-1])) s.insert(cur);
                cur="";
            }
            else if (cur=="0") cur=string(1,word[i]);
            else cur+=word[i];
        }
        if (cur!="") s.insert(cur);
        return s.size();
    }
};
