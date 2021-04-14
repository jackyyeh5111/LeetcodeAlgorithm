class Solution {
public:
    string truncateSentence(string s, int k)
    {
        int n=s.length(), i=0;
        string ans="";
        while (i<n&&k>0) {
            string word="";
            while(i<n&&s[i]!=' ') word+=s[i++];
            i++;
            ans+=word+' '; k--;
        }
        return ans.substr(0,ans.size()-1);
    }
};
