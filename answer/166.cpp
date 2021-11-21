/***** Second Visit *****/
/*
    2/3
    0.6
    1/6
    1,6 .
    4,6 .1


*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        bool neg=(numerator>=0)^(denominator>=0);
        long num=numerator,den=denominator;
        num=abs(num); den=abs(den);
        string ans="";
        bool fract=false;
        unordered_map<string,int> m;
        while (num!=0) {
            string k=to_string(num)+"_"+to_string(den);
            if (m.count(k)!=0) {
                ans+=')';
                ans.insert(ans.begin()+m[k]+(ans[m[k]]=='.'),'(');
                break;
            }
            m[k]=ans.length();
            if (fract) num*=10;
            while (num<den) {
                ans+=fract?'0':'.';
                fract=true;
                num*=10;
            }
            long divide=num/den;
            long remain=num%den;
            ans+=to_string(divide);
            num=remain;
            // if (ans.length()>=10) break;
        }
        if (ans.length()==0||ans[0]=='.') ans="0"+ans;
        return (neg&&ans!="0")?"-"+ans:ans;
    }
};

/***** First Visit *****/
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
