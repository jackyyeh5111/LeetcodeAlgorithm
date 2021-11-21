/***** Fifth Visit *****/
class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for (int len=1; len<=n; ++len) {
            for (int i=0; i+len-1<n; ++i) {
                int j=i+len-1;
                if (len==1||s[i]==s[j]&&(len==2||dp[i+1][j-1]))
                    dp[i][j]=true;
            }
        }
        vector<vector<string>> ans;
        vector<string> cur;
        dfs(s,dp,0,cur,ans);
        return ans;
    }

    void dfs(string &s, vector<vector<bool>> &dp, int idx, vector<string> &cur,
             vector<vector<string>> &ans)
    {
        if (idx==s.length()) {
            ans.push_back(cur);
            return;
        }
        for (int i=idx; i<s.length(); ++i) {
            if (dp[idx][i]) {
                cur.push_back(s.substr(idx,i-idx+1));
                dfs(s,dp,i+1,cur,ans);
                cur.pop_back();
            }
        }
    }
};

/***** Fourth Visit(FAIL) *****/
/*
    recursive dfs
    dfs(int idx, string s, vector<string> &cur, vector<vector<string>> &ans)
    if s.substr(0,idx) is palindrome
        cur.push_back(s.substr(0,idx))
        dfs(0,s.substr(idx),cur,ans)
        cur.pop_back()
    dfs(idx+1,s,cur,ans);
    T(n) = T:O(2^n) * palindrome checking T:O(n)
    -----
    divide & conquer
    for i=1~n-1
      string left=s.substr(0,i)
      string right=s.substr(i+1)
      combine partition(left) and partition(right)
    if s is palindrome: add s
    check palindrome O(n)
    -----
    dp[i][j] denotes if s[i-j] is palindrome or not
    dp[i][j] = dp[i+1][j-1] && s[i]==s[j]
    -----
    SEE SECOND VISIT
*/

/***** Third Visit *****/
/*
      a a b a a c
      . . . . . .
    . v v v v v v
    . v x x v x
    . x v x x
    . x x x
    . v x
    . x

    KEY:
    s=left+mid+right, s is palindrom if mid is palindrom and left==right.
    Take O(1) to check palindrom during DP.

    It will take O(n^2) to build the table
    T:O(n!) to traverse

    a a b a a c
    aa b a a c
    aa b aa c
    a a b aa c
    a aba a c
    aabaa c
*/
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> cur;
    vector<vector<string>> partition(string s)
    {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        help(s,0,dp);
        return ans;
    }

    void help(string s, int idx, vector<vector<bool>> &dp)
    {
        if (idx==s.length()) {ans.push_back(cur); return;}
        for (int i=idx; i<s.length(); ++i) {
            if (s[i]==s[idx]&&(idx+2>=i||dp[idx+1][i-1])) {
                dp[idx][i]=true;
                cur.push_back(s.substr(idx,i-idx+1));
                help(s,i+1,dp);
                cur.pop_back();
            }
        }
    }
};

/***** Second Visit *****/
/*
    Directly backtracking on palindrome checking
    T:O(2^n*n)/S:O(n)
    ==> O(2^n) for backtracking
    ==> O(n) for palindrom checking
    -----
    How to make palindrom checking in constant time complexity ?
    s[i+1] to s[j-1] is a palindrom annd s[i]==s[j]
    Thus we could handle a DP approach for help.
    T:O(2^n)/S:O(n^2)
*/
// check palindrom in T:O(n)
class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> comb;
        help(s,0,"",comb,ans);
        return ans;
    }

    void help(string &s, int i, string pal, vector<string> &comb, vector<vector<string>> &ans)
    {
        if (i>=s.length()) {
            if (pal=="") ans.push_back(comb);
            return;
        }
        help(s,i+1,pal+s[i],comb,ans);
        if (checkPal(pal+s[i])) {
            comb.push_back(pal+s[i]);
            help(s,i+1,"",comb,ans);
            comb.pop_back();
        }
    }

    bool checkPal(string s)
    {
        int l=0,r=s.length()-1;
        while(l<r) {
            if (s[l]!=s[r]) return false;
            l++; r--;
        }
        return true;
    }
};

// check palindrom in T:O(1)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp (len, vector <bool> (len, false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList, vector<vector<bool>> &dp) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
};

/***** First Visit *****/
/************************ Back Tracking ***********************/
class Solution {
public:
    unordered_map<string,bool> cache;
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;

        vector<string> path;
        dfs(0, s, path, ret);

        return ret;
    }

    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) { ret.push_back(path); return; }
        for(int i = index; i < s.size(); ++i) {
            string sub=s.substr(index,i-index+1);
            if(check(sub)) {
                path.push_back(sub);
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
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

/************************* TLE *************************/
class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        /*
            brute force:
            enumerate all possible partition then check if Palindrome or not.
            aabc
                a
                aa,a a
                aab,a ab,aa b,a a b
                aabc,a abc,aa bc,a a bc,aab c,a ab c,aa b c, a a b c
            T:O(2^n)*O(check palindrom)
            -----------------------------------
            Think: abba is palindrom, then is abba+c a palindrom?
            a b c b a a
        */
        vector<vector<string>> ans,perms;
        unordered_map<string,bool> cache;
        if (s.length()>0) perms.push_back(vector<string>{s.substr(0,1)});
        for (int i=1; i<s.length(); ++i) {
            int size=perms.size();
            for (int j=0; j<size; ++j) {
                vector<string> perm=perms[j];
                perm.push_back(s.substr(i,1));
                perms.push_back(perm);
                perm.pop_back(); perm.back()+=s.substr(i,1);
                perms.push_back(perm);
            }
            perms.erase(perms.begin(),perms.begin()+size);
        }
        for (auto perm:perms){
            bool valid=true;
            for (string entry:perm) {
                bool isPalindrome;
                if(cache.find(entry)==cache.end()) {
                    isPalindrome=check(entry);
                    cache[entry]=isPalindrome;
                }
                else isPalindrome=cache[entry];
                if(!isPalindrome) {valid=false; break;}
            }
            if(valid) ans.push_back(perm);
        }
        return ans;
    }

    bool check(string& s)
    {
        string t=s;
        reverse(t.begin(),t.end());
        return t==s;
    }
};
