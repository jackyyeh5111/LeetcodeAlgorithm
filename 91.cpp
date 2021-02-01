/***** Third Visit *****/
/*
    num:          2 2 6
    # of combs: 1 1 2 3
    conduct DP solution.
    max char consumes 2 digits, so checking 1 digit or 2 digits is enough.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int numDecodings(string s)
    {
        int prev=1, prevprev=0, n=s.length();
        for (int i=0; i<n; ++i) {
            int cur=0;
            if (s[i]!='0') cur+=prev;
            if (i>0&&s[i-1]!='0') {
                int num=(s[i-1]-'0')*10+s[i]-'0';
                if (num<=26) cur+=prevprev;
            }
            if (cur==0) return 0;
            prevprev=prev; prev=cur;
        }
        return prev;
    }
};

/***** Second Visit *****/
/*
    backtracking approach
    > 1 <= s.length <= 100
    > notice leading zero
    limited input length could avoid TLE
    STILL TLE
    T:O(2^n)/S:O(n) propotion to depth of recursion
    -----
    1-d dp solution
    dp[i] denotes the # of decode ways on s[0~i].
    dp[i]=dp[i-1]+dp[i-2] if the num of last 2 digits is in the range 11-26
          excludes 20.
         =dp[i-1] if the num of last 2 digits > 26
         =dp[i-2] if the num of last 2 digits == 10 or 20
    T:O(n)/S:O(n)
*/
/***** 1-d DP *****/
class Solution {
public:
    int numDecodings(string s)
    {
        // if (s=="") return 0; // input constraint
        int n=s.length();
        vector<int> dp(n+1,0);
        dp[0]=1; dp[1]=s[0]!='0';
        for (int i=2; i<=n; ++i) {
            int num=stoi(s.substr(i-2,2));
            if (s[i-1]!='0') dp[i]+=dp[i-1];
            if (num>=10&&num<=26) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};

/***** backtracking TLE *****/
class Solution {
public:
    int numDecodings(string s)
    {
        if (s==""||s[0]=='0') return 0;
        else if (s.length()==1&&s[0]>='1'&&s[0]<='9') return 1;
        int num=stoi(s.substr(0,2));
        if (s.length()==2&&(num==10|num==20)) return 1;
        else if (s.length()==2&&num<=26) return 2;
        int ret=numDecodings(s.substr(1));
        if (num<=26) ret+=numDecodings(s.substr(2));
        return ret;
    }

};

/***** First Visit *****/
/************************ AC ************************/
// dp solution, T:O(n), S:O(n)
class Solution {
public:
    int numDecodings(string s)
    {
        // dp[i] denotes # of decodings from 0~i.
        /*
            dp[i]
                if s[i]!=0 dp[i-1]
                if 10<=s[i-1]+s[i] <=26 dp [i-2]
        */
        if (s.length()==0) return 0;
        vector<int> dp(s.length()+1,0);
        dp[0]=1; //sanity check for concise coding
        dp[1]=!(s[0]=='0');
        for (int i=2; i<=s.length(); ++i) {
            int tmp=0;
            if (s[i-1]!='0') tmp+=dp[i-1];
            int num=stoi(s.substr(i-2,2));
            if (num>=10&&num<=26) tmp+=dp[i-2];
            dp[i]=tmp;
        }
        return dp[s.length()];
    }
};

/************************ TLE ************************/
// recursive way will cause TLE on long Sequence test case.
// exponential time, T:O(2^n), S:O(n) <- propotional to depth of recursion
class Solution {
public:
    int numDecodings(string s)
    {
        /*
        recursive
        for each position, check
        if ([pos,pos+1] <=26)
            return numDecodeings(s.substr(pos+1))+numDecodeings(s.substr(pos+2))
        else
            return numDecodeings(s.substr(pos))

        define end condition,
        if s.length()==1 return 1
        if s.length()==2
            if s<=26 return 2
            else return 1
        */
        if (s.length()==0) return 0; // for dummy input
        if (s.length()==1) return !(s=="0");
        if (s.length()==2) {
            int count=0; int num=stoi(s);
            if (num>=10&&num<=26) count++;
            if (s[0]!='0'&&s[1]!='0') count++;
            return count;
        }
        int count=0;
        if (s[0]!='0') count+=numDecodings(s.substr(1));
        int num=stoi(s.substr(0,2));
        if (num>=10&&num<=26) count+=numDecodings(s.substr(2));

        return count;
    }
};
