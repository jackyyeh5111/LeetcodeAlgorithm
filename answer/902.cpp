/*
    Take N = 2563, D = {"1", "2", "6"} as an example,
    The first loop handles the count of x, xx, xxx which x belongs to D. the sum is 3^1 + 3^2 + 3^3.
    The second loop handles xxxx from left most digit.
    For example,
    count of 1xxx is 3^3
    count of 21xx is 3^2
    count of 22xx is 3^2

    If the elements of D can compose entired N, answer + 1
    refers: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/discuss/168439/C%2B%2B-O(logN)-Clear-code-with-explanation
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n)
    {
        string ns=to_string(n);
        int ans=0, m=digits.size();
        if (m==1) ans=ns.length()-1;
        else if (ns.length()>1&&m>1) ans=m*(pow(m,ns.length()-1)-1)/(m-1);

        for (int i=0; i<ns.length(); ++i) {
            bool same=false;
            for (string digit:digits) {
                if (digit[0]<ns[i]) ans+=pow(m, ns.length()-i-1);
                else if (digit[0]==ns[i]) same=true;
            }
            if (!same) return ans;
        }
        return ans+1;
    }
};

// TLE
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n)
    {
        int td=to_string(n).length(),ans=0, m=digits.size();
        comb(digits,0,0,0,td,n,ans);
        int rest=0;
        if (m==1) rest=td-1;
        else if (td>1&&m>1) rest=m*(pow(m,td-1)-1)/(m-1);
        return ans+rest;
    }

    void comb(vector<string>& digits, int idx, int cur, int sd, int td, int n, int &ans)
    {
        if (sd==td&&cur<=n) {
            // cout<<cur<<endl;
            ans++;
            return;
        }
        else if (cur>n||sd>td) return;

        for (int i=0; i<digits.size(); ++i) {
            if ((long)cur*10+(long)stoi(digits[i])<=(long)n) {
                comb(digits,idx+1,cur*10+stoi(digits[i]),sd+1,td,n,ans);
            }
            else break;
        }
    }
};
