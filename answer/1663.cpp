/*
    Find smallest lexiocn order
    aaszz 5, 71 -52 19
      ^
    abcdefghijklmnopqrstuvwxyz
    T:O(n)/S:O(1)

*/

// backward
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = string(n, 'a');
        k -= n;
        while (k > 0) {
            res[--n] += min(25, k);
            k -= min(25, k);
        }
        return res;
    }
};

// forward
class Solution {
public:
    string getSmallestString(int n, int k)
    {
        string ans="";
        for (int i=0; i<n; ++i) {
            int t=(n-i-1)*26;
            if (t>=k) {ans+='a'; k--;}
            else {ans+=(k-t)+'a'-1; k=t;}
        }
        return ans;
    }
};
