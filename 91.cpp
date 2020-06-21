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
