/******************************* Second Visit *******************************/
class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        n = (n>>16) | (n<<16);
        n = ((n&0xff00ff00)>>8) | ((n&0x00ff00ff)<<8);
        n = ((n&0xf0f0f0f0)>>4) | ((n&0x0f0f0f0f)<<4);
        n = ((n&0xcccccccc)>>2) | ((n&0x33333333)<<2);
        n = ((n&0xaaaaaaaa)>>1) | ((n&0x55555555)<<1);
        return n;
    }
};

/******************************* First Visit *******************************/
/************ for loop needed ************/
class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        /*
            1. reverse: stack!
            2. start from lsb

        */
        uint32_t ans=0;
        for (int i=0; i<32; ++i) {
            ans=(ans<<1)+(n&1);
            n=n>>1;
        }
        return ans;
    }
};

/************ block of bits swapping, no for loop needed ************/
class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        /*
            abcd efgh
            efgh abcd
            ghef cdab
            hgfe dcba
        */
        n=(n>>16)|(n<<16);
        n=((n&0xff00ff00)>>8)|((n&0x00ff00ff)<<8);
        n=((n&0xf0f0f0f0)>>4)|((n&0x0f0f0f0f)<<4);
        n=((n&0xcccccccc)>>2)|((n&0x33333333)<<2); // 1100 0011
        n=((n&0xaaaaaaaa)>>1)|((n&0x55555555)<<1); // 1010 0101
        return n;
    }
};
