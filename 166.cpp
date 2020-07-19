class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        /*
            For dividor, we can actually finish with one step:
            divider=numerator/denominator; cur=numerator%denominator;

            Notice tons of edge cases...
            ---- fraction with leading 0, 0.001...
            4
            333
            ---- divider is 0 or ""
            1
            2
            ----0.1(6) repeat fraction with index i (i!=0)
            1
            6
            ---- divider with leading zero and padding zero.
            500
            10
            ---- negative integer
            -50
            8
            ---- 0 or -0
            0
            -5
            ---- overflow
            -1
            -2147483648
        */
        bool negative=(numerator>=0)^(denominator>=0);
        long numerator_=numerator; long denominator_=denominator;
        numerator_=abs(numerator_); denominator_=abs(denominator_);
        vector<long> num;
        while(numerator_!=0) {
            num.insert(num.begin(),numerator_%10);
            numerator_ /= 10;
        }
        string divider="";
        long cur=0;
        for (int i=0; i<num.size(); ++i) {
            cur=cur*10+num[i];
            if (cur<denominator_) {
                if (divider!="")
                    divider+="0";
                continue;
            }
            divider+=to_string(cur/denominator_);
            cur=cur%denominator_;
        }
        unordered_map<long,int> s;
        string fraction=""; int index=0;
        while(s.find(cur)==s.end()&&cur!=0) {
            s[cur]=index++;
            cur*=10;
            if (cur<denominator_) {fraction+="0"; continue;}
            fraction+=to_string(cur/denominator_);
            cur=cur%denominator_;
        }
        string ans= divider==""?"0":divider;
        if (fraction!=""&&cur!=0) {
            fraction.insert(fraction.begin()+s[cur],'(');
            ans+="."+fraction+")";
        }
        else if ((fraction!=""&&cur==0)) ans+="."+fraction;
        // cout<<divider<<endl;
        // cout<<fraction<<endl;
        if (negative&&ans!="0") ans.insert(ans.begin(),'-');
        return ans;
    }
};
