/***** Sixth Visit *****/
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty()) return 0;
        vector<int> failure;
        help(failure,needle);
        int m=haystack.length(), n=needle.length(), i=0, j=0;
        while (m-i>=n-j) {
            if (haystack[i]==needle[j]) {i++; j++;}
            else if (j==0) i++;
            else j=failure[j-1];
            if (j==n) return i-j;
        }
        return -1;
    }

    void help(vector<int> &failure, string s)
    {
        failure.push_back(0);
        int n=s.length();
        for (int i=1; i<n; ++i) {
            int j=failure[i-1];
            while (j!=0&&s[i]!=s[j]) j=failure[j-1];
            failure.push_back(j+(s[i]==s[j]));
        }
    }
};

/***** Fourth Visit *****/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle=="") return 0;
        else if (haystack=="") return -1;
        vector<int> failure;
        help(failure,needle);
        int i=0,j=0,m=haystack.length(),n=needle.length();
        while (i+n<=m+j) {
            while (j!=0&&haystack[i]!=needle[j])
                j=failure[j-1];
            j+=(haystack[i]==needle[j]); i++;
            if (j==n) return i-j;
        }
        return -1;
    }

    void help(vector<int> &v, string needle)
    {
        v.push_back(0);
        int n=needle.length();
        for (int i=1; i<n; ++i) {
            int j=v[i-1];
            while (j!=0&&needle[j]!=needle[i]) j=v[j-1];
            if (j==0) v.push_back(needle[0]==needle[i]);
            else v.push_back(j+1);
        }
    }
};

/***** Third Visit *****/
/*
    String Comparison
    brute force:
        enumerate all possible substring and do string comparison
        T:O(n^2*k) where k is the length of needle.
    -----
    KMP
        T:O(m+n)
*/
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if (needle=="") return 0;
        vector<int> failure=getFailure(needle);
        int i=0,j=0,m=haystack.length(),n=needle.length();
        while (n-j<=m-i) {
            if (haystack[i]==needle[j]) {j++; i++;}
            else if (j==0) i++;
            else j=failure[j-1];
            // cout<<i<<","<<j<<endl;
            if (j==n) return i-n;
        }
        return -1;
    }

    // failure[i]=k denotes s[0~k]==s[i-k~i]
    // failure[i]= failure[i-1]+1 if s[i]==s[failure[i]+1]
    //             else check failure[failure[i-1]]
    vector<int> getFailure(string s)
    {
        int n=s.length();
        vector<int> failure(n,0);
        for (int i=1; i<n; ++i) {
            int j=failure[i-1];
            while (j!=0&&s[j]!=s[i]) j=failure[j-1];
            if (s[j]==s[i]) failure[i]=j+1;
            else failure[i]=0;
        }
        return failure;
    }
};

/***** Second Visit *****/
/*
    knuth morris pattern
    Note:
        while loop in getFailure, if p[i]!=p[j+1], j=pi[j] which means if this char
        fail, we look backward to the previous same char.

        i-j<=m-n -> n-j<=m-i
        It means the rest of uncheked string must longer than the rest of unchecked
        pattern, or we won't find the match one.
*/
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if(needle=="") return 0;
        else if (haystack=="") return -1;
        vector<int> failure=getFailure(needle);
        int m=haystack.length(),n=needle.length();
        int i=0,j=0;
        while(i-j<=m-n) { // n-j <= m-i
            if (j>0&&haystack[i]!=needle[j])
                j=failure[j-1];
            else if (haystack[i]==needle[j]){
                i++; j++;
            }
            else i++;
            if(j>=n) return i-j;
        }
        return -1;
    }

    vector<int> getFailure(string pattern)
    {
        vector<int> ret;
        ret.push_back(0);
        int n=pattern.length();
        for (int i=1; i<n; ++i) {
            int j=ret[i-1];
            while(j>0 && pattern[j]!=pattern[i]) j=ret[j-1];
            if (pattern[j]==pattern[i]) ret.push_back(j+1);
            else ret.push_back(0);
        }
        return ret;
    }
};

/***** First Visit *****/
/********* Knuth-Morris-Pratt ************/
class Solution {
public:
    // T:O(m+n), S:O(m)
    // Notice j, 33% for j-- and 90% for j=ans[j-1]
    int strStr(string haystack, string needle)
    {
        if (needle=="") return 0;
        else if (haystack=="") return -1;

        vector<int> failure = getFailure(needle);
        int haystack_size = haystack.length();
        int needle_size = needle.length();
        int i=0, j=0;
        while(j-i <= haystack_size-needle_size) {
            if (i>0 && haystack[j]!=needle[i])
                i = failure[i-1];
            else if (haystack[j]==needle[i]) {
                i++; j++;
            }
            else
                j++;

            if (i>needle.size()-1)
                return j-i;
        }
        return -1;
    }

    vector<int> getFailure(string pattern)
    {
        vector<int> ans;
        ans.push_back(0);
        for (int i=1; i<pattern.size(); ++i) {
            int j=ans[ans.size()-1];
            while (j>0&&pattern[j]!=pattern[i]) j=ans[j-1]; // j--
            if (pattern[i] == pattern[j])
                ans.push_back(j+1);
            else
                ans.push_back(0);
        }
        return ans;
    }
};
