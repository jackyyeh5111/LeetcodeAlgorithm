class Solution {
public:
    int hammingDistance(int x, int y)
    {
        /*
            countBits(x^y)

            0110101100
            0110101011

            0110101000
            0110100111

            0110100000
        */
        int z=x^y; int sum=0;
        while(z){
            sum++;
            z=z&(z-1); // Brian Kernighan's algorithm
        }
        return sum;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y)
    {
        /*
            countBits(x^y)
        */
        int z=x^y; int sum=0;
        for(int i=0; i<32; ++i){
            sum+=z&1; z=z>>1;
        }
        return sum;
    }
};
