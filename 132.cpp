/***** Fifth Visit *****/
/*
    FAIL, SEE THIRD VISIT.
*/

/***** Fourth Visit *****/
/*
    FAIL, SEE THIRD VISIT.
*/

/***** Third Visit *****/
/*
    dp[i][j] denotes minCuts from i to j
    dp[i][j]=min(dp[i][k-1]+dp[k+1][j]+1)
    Recursive?
    T(n)= (T(n-2)+T(1)+...+T(1)+T(n-2))*n + O(n)
        = (T(1)+...+T(n-2))*2 + O(n)
        = O(n^3)
    -----
    dp[i] denotes minCut from 0-i, compare head and tail for palindrom checking.
    Same as problem 131.
*/
class Solution {
public:
    int minCut(string s)
    {
        int n=s.length();
        vector<int> dp(n,0);
        for (int i=0; i<n; ++i) dp[i]=i+1;
        for (int i=0; i<n; ++i) {
            int j=i, k=i;
            while (j>=0&&k<n&&s[j]==s[k]) {
                int left=j>0?dp[j-1]+1:0;
                dp[k]=min(dp[k],left);
                j--; k++;
            }
            j=i, k=i+1;
            while (j>=0&&k<n&&s[j]==s[k]) {
                int left=j>0?dp[j-1]+1:0;
                dp[k]=min(dp[k],left);
                j--; k++;
            }
        }
        return dp[n-1];
    }
};

/***** Second Visit *****/
/*
    FAIL, no concept.
    backtracking will cause TLE. Use dp instead.
    Use the concept as problem 131. Compare head/tail and see if palindrom, which starts from the mid position.
    dp[i] denotes the min cut needed from 0 to i.
    dp[i]=min(dp[i],dp[i-j]+1,dp[i-j-1]+1)
    We should treat odd length/even length as 2 separate item to check.
    T:O(n^2)/S:O(n)
*/
class Solution {
public:
    int minCut(string s)
    {
        int n=s.length();
        if (n<=1) return 0;
        vector<int> dp(n+1,0);
        for (int i=0; i<=n; ++i) dp[i]=i-1;
        for (int i=1; i<n; ++i) {
            for (int j=0; i-j>=0&&i+j<n&&s[i-j]==s[i+j]; j++)
                dp[i+j+1]=min(dp[i+j+1],dp[i-j]+1);
            for (int j=0; i-j>=1&&i+j<n&&s[i-j-1]==s[i+j]; ++j)
                dp[i+j+1]=min(dp[i+j+1],dp[i-j-1]+1);
        }
        return dp[n];
    }
};

/***** First Visit *****/
/********************** Manancher-like solution **********************/
/*
    Only check those sub-strings centered at s[i], once a non-palindrome string
    is found, it will stop and move to i+1.
    This is why its faster than DP. DP doesn't handle early stop.
*/
class Solution {
public:
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
