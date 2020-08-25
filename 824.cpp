/*
    brute force
    T:O(n)/S:O(1)
*/
class Solution {
public:
    string toGoatLatin(string S)
    {
        bool isVowel[26]={false};
        isVowel['a'-'a']=true; isVowel['e'-'a']=true; isVowel['i'-'a']=true;
        isVowel['o'-'a']=true; isVowel['u'-'a']=true;
        string ans;
        int n=S.length(); int count=0;
        for (int i=0; i<n; ++i) {
            string word="";
            while(i<n&&S[i]!=' ') word+=S[i++];
            count++;
            if (word=="") continue;
            else if (isVowel[tolower(word[0])-'a']) word+="ma";
            else word=word.substr(1)+word[0]+"ma";
            for(int x=0; x<count; ++x) word+="a";
            // cout<<word<<endl;
            ans+=word+" ";
        }
        return ans.substr(0,ans.length()-1);
    }
};
