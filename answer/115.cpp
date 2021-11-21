/***** Fifth Visit *****/
/*
    dp[i][j] denotes distinct subsequences from s[0-i-1] to t[0-j-1]
    dp[i][j] = dp[i-1][j-1] if s[i-1]==t[j-1]
               + dp[i-1][j]
    T:O(mn)/S:O(mn)
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.length(), n=t.length();
        vector<long> dp(n+1,0);
        for (int i=1; i<=m; ++i) {
            int prev=1;
            for (int j=1; j<=n; ++j) {
                int temp=dp[j];
                if (s[i-1]==t[j-1]) dp[j]+=prev;
                prev=temp;
            }
        }
        return dp[n];
    }
};

/***** Fourth Visit *****/
/*
    LISequence
    dp[i][j] denotes max length of LIS
    dp[i][j] if i==j dp[i-1][j-1]+1
             else max(dp[i][j-1],dp[i-1][j])
    -----
    dp[i][j] denotes max distinct subsequence of t[0-i] and s[0-j]
    dp[i][j] dp[i][j-1]+(s[i]==s[j]?dp[i-1][j-1]:0)
      r a b b b i t
    r 1 1 1 1 1 1 1
    a 0 1 1 1 1 1 1
    b 0 0 1 2 3 3 3
    b 0 0 0 1 3 3 3
    i
    t
    T:O(mn)/S:O(n)
*/

/***** Third Visit *****/
/*
    recursive first, find the pattern:
    if s[i]==t[j], we can choose 2 options: match s[i] with t[j], or ignore s[i].
    else we can only ignore s[i]
    TLE
    -----
    DP solution?
    dp[i][j] denotes the # of distinct w. s[0-i] and t[0-j]
    dp[i][j] = dp[i-1][j-1]+dp[i-1][j] if s[i]==t[j]
               dp[i-1][j] if s[i]!=t[j]
      . r a b b i t
    . 1 0 0 0 0 0 0
    r 0 1 0 0 0 0 0
    a 0 0 1 0 0 0 0
    b 0 0 1 1 0 0 0
    b 0 0 1 2 1 0 0
    b
    i
    t
*/

class Solution {
public:
    int numDistinct(string s, string t)
    {
        int ans=0, m=s.length(), n=t.length();
        help(s,t,0,0,m,n,ans);
        return ans;
    }

    void help(string s, string t, int i, int j, int m, int n, int &ans)
    {
        if (j==n) {ans++; return;}
        else if (i>=m) return;
        if (s[i]==t[j])
            help(s,t,i+1,j+1,m,n,ans);
        help(s,t,i+1,j,m,n,ans);
    }
};

class Solution {
public:
    int numDistinct(string s, string t)
    {
        int m=s.length(), n=t.length();
        vector<long> dp(n+1,0);
        dp[0]=1;
        for (int i=1; i<=m; ++i) {
            long prev=dp[0];
            for (int j=1; j<=n; ++j) {
                long tmp=dp[j];
                if (s[i-1]==t[j-1]) dp[j]+=prev;
                prev=tmp;
            }
        }
        return dp[n];
    }
};

/***** Second Visit *****/
/*
    string
    1. TRIE
    2. KMP - failure function
    3. treat it as array.
    -----
    brute force:
    enumerate all possible substring then compare
    T:O(2^k * n)/S:O(1)
    -----
    rabbbit

    rabbit
    top-down -> LCS
    bottomm-up -> find possible ways.
    T:O(mn)/S:O(mn)
    -----
    recursive TLE
    T:O(2^(m+n))/S:O(m+n)
    -----
    dp[i][j] denotes the number of same subsequence with s[0-i] & t[0-j]
    dp[i][j] = dp[i-1][j-1]+dp[i-1][j] if s[i-1]==t[j-1]
             = dp[i-1][j] if s[i-1]!=t[j-1]
     . a c
    .1 0 0
    b0 0 0
    b0 0 0
    b0 0 0
    a0 0 0
    c0 0 0
    T:O(mn)/S:O(n)
*/
// 1-D dp AC
class Solution {
public:
    int numDistinct(string s, string t)
    {
        vector<long> dp(t.length()+1,0);
        dp[0]=1;
        for (int i=1; i<=s.length(); ++i) {
            long prev=dp[1]; dp[1]+=(s[i-1]==t[0]);
            for (int j=2; j<=t.length(); ++j) {
                int tmp=dp[j];
                if (s[i-1]==t[j-1]) dp[j]+=prev;
                prev=tmp;
            }
        }
        return dp[t.length()];
    }
};

// recursive TLE
class Solution {
public:
    int numDistinct(string s, string t)
    {
        int ans=0;
        help(s,t,s.length(),t.length(), ans);
        return ans;
    }

    void help(string s, string t, int i, int j, int &ans)
    {
        if (j==0) {ans++; return;}
        else if (i==0) return;
        else if (s[i-1]==t[j-1]) {
            help(s,t,i-1,j-1,ans);
        }
        help(s,t,i-1,j,ans);
    }
};

/***** First Visit *****/
class Solution {
public:
    int count=0;
    int numDistinct(string s, string t)
    {
        /*
            First come up with recursive approach, then we can try DP for
            time/space tradeoff.
            ----------- recursive: TLE, try DP -----------
            dp[i][j] denotes numDistinct of s[0-i-1] and t[0-j-1]
            dp[i][j]:
                case1: dp[i-1][j] s[i-1]!=t[j-1]
                case2: dp[i-1][j-1] s[i-1]==t[j-1]
        */
        vector<vector<long>> dp(s.length()+1, vector<long>(t.length()+1,0));
        for (int i=0; i<=s.length(); ++i) dp[i][0]=1;
        for (int i=1; i<=s.length(); ++i) {
            for (int j=1; j<=t.length(); ++j) {
                dp[i][j]=dp[i-1][j];
                if (s[i-1]==t[j-1]) dp[i][j]+=dp[i-1][j-1];
            }
        }

        return dp[s.length()][t.length()];
    }
};

/******************* Reduce to 1-d DP approach**********************/
class Solution {
public:
    int count=0;
    int numDistinct(string s, string t)
    {
        vector<long> dp(t.length()+1,0);
        dp[0]=1;
        for (int i=1; i<=s.length(); ++i) {
            int prev=dp[0];
            for (int j=1; j<=t.length(); ++j) {
                int tmp=dp[j];
                dp[j] = s[i-1]==t[j-1]?dp[j]+prev:dp[j];
                prev=tmp;
            }
        }

        return dp[t.length()];
    }
};

/******************* Recursive TLE **********************/
class Solution {
public:
    int count=0;
    int numDistinct(string s, string t)
    {
        help(s,t,0,0);
        return count;
    }

    void help(string &s, string &t, int i, int j)
    {
        if (j==t.length()) { count++; return; }
        if (i>=s.length()) return;

        if(s[i]==t[j]) help(s,t,i+1,j+1);
        help(s,t,i+1,j);
    }
};
