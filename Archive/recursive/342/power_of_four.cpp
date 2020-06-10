class Solution {
public:
    /*
    bool isPowerOfFour(int num) {
        if(num==1) return true;
        if(num%4!=0 || num<4) return false;
        return isPowerOfFour(num/4);
    }
    */
    bool isPowerOfFour(int num) {
        // power of 2 / power of 4
        return (num&num-1 ==0) && (num&0xaaaaaaaa==0);    
    }
};
