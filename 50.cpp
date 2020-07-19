/************************ Second Visit ************************/
class Solution {
public:
    double myPow(double x, int n)
    {
        /*
            brute force: O(n)
            think: O(logN)
            1010
        */
        bool pos=n>=0;
        long n_l = labs(n);
        if (x==1) return 1;
        else if (x==-1) return n_l%2? -1:1;
        double ans=1; double k=x;
        while (n_l) {
            if (n_l&1) ans*=k;
            k*=k;
            n_l=n_l>>1;
        }
        if (pos) return ans;
        else return 1/ans;
    }
};

/************************ First Visit ************************/
class Solution {
public:
    double myPow(double x, int n) {
        // brute force O(n)
        // binary search O(logn)
        if(n==0) return 1;
        bool sign=n>0; long n_l=labs(n);
        double ans=1;
        while(n_l>0) {
            // cout<<x<<","<<n_l<<endl;
            if (n_l&1) ans = ans*x;
            x=x*x;
            n_l = n_l>>1;
        }
        return sign?ans:(double)1.0/ans;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        // brute force O(n)
        // binary search O(logn)
        if(n==0) return 1;
        bool sign=n>0; double n_d=fabs(n);
        double cur=x; double pow=1; double ans=1;
        while(pow!=n_d) {
            // cout<<x<<","<<pow<<","<<n_d<<endl;
            if (pow*2<=n_d) {
                pow*=2;
                cur*=cur;
            }
            else {
                ans *= cur;
                n_d-=pow;
                pow=1; cur=x;
            }
        }
        if (pow==n_d) ans *= cur;
        return sign?ans:(double)1/(double)ans;
    }
};
