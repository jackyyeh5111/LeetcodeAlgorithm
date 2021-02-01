/***** Second Visit *****/
/*
    T:O(n^2)/S:O(1)
*/
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n=s.length(), curL=0;
        string ans="";
        for (int i=0; i<n; ++i) {
            int j=i, k=i;
            while(k<n&&j>=0&&s[j]==s[k]) {j--; k++;}
            if (k-j-1>curL) {
                curL=k-j-1;
                ans=s.substr(j+1,k-j-1);
            }
            j=i;k=i+1;
            if (k>=n||s[j]!=s[k]) continue;
            while(k<n&&j>=0&&s[j]==s[k]) {j--; k++;}
            if (k-j-1>curL) {
                curL=k-j-1;
                ans=s.substr(j+1,k-j-1);
            }
        }
        return ans;
    }
};

/***** First Visit *****/
/*
    brute force
    enumerate all substring then check palindrom
    T:O(C^n_2*n)=O(n^3)/S:O(1)
    ------------
    reverse the string then find LCS

    NOTE: should check palindrom while finding max LCS
    We could see that the longest common substring method fails when there
    exists a reversed copy of a non-palindromic substring in some other part of
    S. To rectify this, each time we find a longest common substring
    candidate, we check if the substring’s indices are the same as the reversed
    substring’s original indices.
    T:O(n^2)/S:(n)
    -----------
    Another DP
    state(s, e) is true:
    for s = e,
    for s + 1 = e,  if str[s] == str[e]
    for s + 2 <= e, if str[s] == str[e] && state(s + 1, e - 1) is true
    T:O(n^2)/S:O(1)
    WRONG ANS!!
    "aacabdkacaa"
    -----------
    use a moving window (hashmap, k:char,v:idx)
    T:O(n^2)/S:O(n)
    WRONG ANS!!
*/

// Wrong Ans
class Solution {
public:
    string longestPalindrome(string s)
    {
        string rs=s;
        reverse(rs.begin(),rs.end());
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                if (s[i-1]==rs[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=0;
            }
        }
        int max_length=0, idx=0;
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                if (dp[i][j]>max_length&&s[i-1]==s[i-dp[i][j]]) {
                    max_length=dp[i][j];
                    idx=i;
                }
            }
        }
        cout<<idx<<","<<max_length<<endl;
        return s.substr(idx-max_length,max_length);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if (n<=1) return s;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for (int i=0; i<n; ++i) dp[i][i]=true;

        int max_length=1,idx=0;
        for (int start=n-1; start>=0; --start) {
            for (int end=start+1; end<n; ++end) {
                if (s[start]==s[end]) {
                    if (end-start==1||dp[start+1][end-1]) {
                        dp[start][end]=true;
                        if (end-start+1>max_length) {
                            max_length=end-start+1;
                            idx=start;
                        }
                    }
                }
            }
        }
        return s.substr(idx,max_length);
    }
};
