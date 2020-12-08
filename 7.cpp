/*
    check sign bit. Notice overflow
    Notice negative number calculation
*/

/****** use LONG ******/
class Solution {
public:
    int reverse(int x)
    {
        bool pos=x>0;
        x=abs(x);
        long ans=0;
        while(x) {
            ans=ans*10+x%10;
            x/=10;
        }
        if (!pos) ans*=-1;
        if (ans>INT_MAX||ans<INT_MIN) return 0;
        else return ans;
    }
};

/****** use runtime checking ******/
class Solution {
public:
    int reverse(int x)
    {
        int ans=0;
        while(x) {
            int r=x%10;
            int d=x/10;
            if (ans>INT_MAX/10||(ans==INT_MAX/10&&r>7)) return 0;
            if (ans<INT_MIN/10||(ans==INT_MIN/10&&r<-8)) return 0;
            ans=ans*10+r;
            x/=10;
        }
        return ans;
    }
};
