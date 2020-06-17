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

// Bit solution O(long32)==O(1)
class Solution {
public:
    int mySqrt(int x)
    {
        long ans = 0;
        long bit = 1l << 16;
        while(bit > 0) {
            ans |= bit;
            if (ans * ans > x) {
                ans ^= bit;
            }
            bit >>= 1;
        }
        return (int)ans;
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
