/*
    make sure to check the order of word1[i~n1] and word2[j~n2] while visitnig i, j.
    T:O(n^2)/S:O(1)
*/
class Solution {
public:
    string largestMerge(string word1, string word2)
    {
        int n1=word1.length(), n2=word2.length(),p=0,q=0;
        string ans="";
        while(p<n1&&q<n2) {
            if (word1[p]>word2[q]) ans+=word1[p++];
            else if (word1[p]<word2[q]) ans+=word2[q++];
            else {
                string s1=word1.substr(p), s2=word2.substr(q);
                if (s1>s2) ans+=word1[p++];
                else ans+=word2[q++];
            }
        }
        while(p<n1) ans+=word1[p++];
        while(q<n2) ans+=word2[q++];
        return ans;
    }
};
