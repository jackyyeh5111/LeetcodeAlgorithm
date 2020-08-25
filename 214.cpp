/**************** KMP ****************/
class Solution {
public:
    // T:O(n), S:O(n)
    string shortestPalindrome(string s)
    {
        /*
            KMP
            aabca#acbaa
            01001010012

            acca#acca
            000101234

            aaac#caaa
            012000123
            In TLE approach, we reserved the original string ss and stored it
            as rev. We iterate over i and check for s[0:n-i] == rev[i:].
            Pondering over this statement, this is the process of failure table in KMP.

            refers to the solution: https://leetcode.com/problems/shortest-palindrome/
        */
        int n=s.size();
        string rev(s);
        reverse(rev.begin(),rev.end());
        string new_s=s+"#"+rev;
        int new_size=new_s.size();
        vector<int> table(new_size,0);
        for (int i=1; i<new_size; ++i) {
            int t=table[i-1];
            while(t>0&&new_s[t]!=new_s[i])
                t=table[t-1];
            if (new_s[i]==new_s[t]) t++;
            table[i]=t;
        }
        return rev.substr(0,n-table.back())+s;
    }
};

/**************** TLE O(n^2) start from middle ****************/
class Solution {
public:
    string shortestPalindrome(string s)
    {
        int mid = (s.length()+1)/2-1;
        int max_mid=0, max_length=0;
        bool odd=true;
        for (int i=mid; i>=0; --i) {
            int l=i-1,r=i+1, length=0;
            while(l>=0&&r<s.length()) {
                if (s[l]!=s[r]) break;
                length++; l--; r++;
            }
            if (length>0&&i-length==0) {
                max_length=length; max_mid=i;
                break;
            }

            l=i-1; r=i; length=0;
            while(l>=0&&r<s.length()) {
                if (s[l]!=s[r]) break;
                length++; l--; r++;
            }
            if (length>0&&i-length==0) {
                max_length=length; max_mid=i;
                odd=false;
                break;
            }
        }
        // cout<<max_mid<<","<<max_length<<endl;
        string prefix="";
        int start;
        if (odd) start=max_mid+max_length+1;
        else start=max_mid+max_length;
        for (int i=start; i<s.length(); ++i)
            prefix+=s[i];
        reverse(prefix.begin(),prefix.end());
        return prefix+s;
    }
};

/**************** TLE O(n^2) ****************/
class Solution {
public:
    string shortestPalindrome(string s)
    {
        /*
            find the shortest mid index first. T:O(n^2)
            complete front part. T:O(n)
        */
        int n=s.size();
        string rev(s);
        reverse(rev.begin(),rev.end());
        int j=0;
        for (int i=0; i<n; ++i) {
            if (s.substr(0,n-i)==rev.substr(i))
                return rev.substr(0,i)+s;
        }
        return "";
    }
};
