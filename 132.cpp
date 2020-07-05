/********************** Manancher-like solution **********************/
/*
    Only check those sub-strings centered at s[i], once a non-palindrome string
    is found, it will stop and move to i+1.
    This is why its faster than DP. DP doesn't handle early stop.
*/
class Solution {
public:
    vector<vector<string>> ret;
    unordered_map<string,bool> cache;
    int minCut(string s)
    {
        if (s.length()<1) return 0;
        vector<int> mincut(s.length()+1,0);
        for (int i=0; i<s.length()+1; ++i) mincut[i]=i-1;

        for (int i=1; i<s.length(); ++i) {
            // for odd length palindrom
            for (int j=0; (i-j)>=0&&(i+j)<s.length()&&s[i-j]==s[i+j]; ++j)
                mincut[i+j+1]=min(mincut[i+j+1],mincut[i-j]+1);

            // for even length palindrom
            for (int j=0; (i-j)>=1&&(i+j)<s.length()&&s[i-j-1]==s[i+j]; ++j)
                mincut[i+j+1]=min(mincut[i+j+1],mincut[i-j-1]+1);

        }
        return mincut[s.length()];
    }
};

/*************************** DP TLE ***************************/
class Solution {
public:
    vector<vector<string>> ret;
    unordered_map<string,bool> cache;
    int minCut(string s)
    {
        /*
            backtracking will lead TLE
            even use big endian backtracking and return first level,
            we will meet edge case:
                aaabaa
                big endian will first return "aa b aa" but ans is a "aabaa".
            Use DP for time connsuming
        */
        vector<int> mincut(s.length()+1,0);
        for (int i=0; i<s.length()+1; ++i) mincut[i]=i-1;

        for (int i=1; i<s.length(); ++i) {
            for (int j=i; j>=0; --j){
                string sub=s.substr(j+1,i-j-1);
                if (s[i]==s[j]&&(i-j<2||check(sub))){
                    mincut[i+1]=min(mincut[i+1],1+mincut[j]);
                }
            }
        }
        return mincut[s.length()];

    }

    bool check(string& s)
    {
        if(cache.find(s)!=cache.end()) return cache[s];
        string t=s;
        reverse(t.begin(),t.end());
        bool isPalindrome=s==t;
        cache[s]=isPalindrome;
        return t==s;
    }


};
