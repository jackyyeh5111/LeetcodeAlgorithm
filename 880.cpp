/*
    Forward: count the position with length K.
    Backward: find the exact index in terms of S.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long n=0, i=0;
        for (; n<K; ++i) {
            n=isalpha(S[i])?n+1:n*(S[i]-'0');
        }
        while (i--) {
            if (isdigit(S[i])) {
                n/=(S[i]-'0');
                K%=n;
            }
            else {
                if (K%n==0) return string(1,S[i]);
                else n--;
            }
        }
        return "";
    }
};
/*
"y959q969u3hb22odq595"
222280369
"cpmxv8ewnfk3xxcilcmm68d2ygc88daomywc3imncfjgtwj8nrxjtwhiem5nzqnicxzo248g52y72v3yujqpvqcssrofd99lkovg"
480551547
*/
