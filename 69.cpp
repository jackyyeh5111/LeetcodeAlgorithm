/***** Third Visit *****/
/*
    binary search
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    int mySqrt(int x) {
        int l=0, r=x/2+1;
        while (l<=r) {
            long mid=l+(r-l)/2;
            if (mid*mid==x) return mid;
            else if (mid*mid>x) r=mid-1;
            else l=mid+1;
        }
        return r;
    }
};

/***** Second Visit *****/
/*
    brute force:
    top-down checking 0-x/2 to find max sqrt.
    T:O(n)/S:O(1)
    TLE!!!
    -----
    speed up linear finding
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    int mySqrt(int x)
    {
        int l=0,r=x/2+2;
        while(l<r) {
            int mid=(l+r)/2;
            if((long)mid*(long)mid>x) r=mid;
            else l=mid+1;
        }
        return l-1;
    }
};
/***** First Visit *****/
/*
Newton's Method Xn+1=1/2(Xn+a/Xn), where a is target x.
The intuition is very simple: if xn is too big (>√a), then a/xn will be too
small (<√a), and so their arithmetic mean xn+1 will be closer to √a.
*/

class Solution {
public:
    int mySqrt(int x)
    {
        if (x == 1)
            return 1;
        float y = 1;
        float old = 0;
        while ((int) (old - y) != 0) {
            old = y;
            y = (y + x * 1.0f / y) * 0.5f;  //Iterative Convergence
        }
        int res = (int) y;
        return res * res > x ? res - 1 : res;//accommodate the Q
    }
};

// Bit solution O(log32)==O(1)
class Solution {
public:
    int mySqrt(int x)
    {
        int ans = 0; // no need to define as "long"
        int bit = 1 << 15; // no need to define as "long"
        while (bit > 0) {
            ans |= bit;
            // the original condition is "ans * ans > x" or "((long)ans) * ((long)ans) > x", this is revised version.
            if (ans > x / ans) {
                // if ans * ans > x, then ans = (ans | bit) ^ bit = ans | (bit ^ bit) = ans (the "previous" ans).
                ans ^= bit;
            }
            bit >>= 1;
        }
        return ans;
    }
};

//O(logn)
class Solution {
public:
    int mySqrt(int x)
    {
        // 0 - ceil(x/2) find sqrt
        // O(logN)
        // brute force: T:O(n)
        int l=0; int r=ceil((float)x/2.0);
        while(l<=r) {
            // cout<<l<<","<<r<<endl;
            int mid=(l+r)/2;
            long sqr=(long)mid*(long)mid;
            if (sqr==(long)x) return mid;
            else if (sqr<(long)x) l=mid+1;
            else if (sqr>(long)x) r=mid-1;
        }
        return r;
    }
};
