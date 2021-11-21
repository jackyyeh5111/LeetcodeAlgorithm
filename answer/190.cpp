/***** Fifth Visit *****/
/*
    32 bits
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans=n;
        ans=(ans&0x0000FFFF)<<16|(ans&0xFFFF0000)>>16;
        ans=(ans&0x00FF00FF)<<8|(ans&0xFF00FF00)>>8;
        ans=(ans&0x0F0F0F0F)<<4|(ans&0xF0F0F0F0)>>4;
        ans=(ans&0x33333333)<<2|(ans&0xCCCCCCCC)>>2;
        ans=(ans&0x55555555)<<1|(ans&0xAAAAAAAA)>>1;
        return ans;
    }
};

/***** Fourth Visit *****/
/*
    1234
    3412
    4321
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans=n;
        ans=((ans&(0xFFFF0000))>>16)|((ans&(0x0000FFFF))<<16);
        ans=((ans&(0xFF00FF00))>>8)|((ans&(0x00FF00FF))<<8);
        ans=((ans&(0xF0F0F0F0))>>4)|((ans&(0x0F0F0F0F))<<4);
        ans=((ans&(0xCCCCCCCC))>>2)|((ans&(0x33333333))<<2);
        ans=((ans&(0xAAAAAAAA))>>1)|((ans&(0x55555555))<<1);
        return ans;
    }
};

/***** Third Visit *****/
/*
    Follow up: If this function is called many times, how to optimize it?
    0110 0101
    0101 0110
    01 01 01 10
    01 01 10 01
    10 10 01 10
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        n=((n&0xFFFF0000)>>16)|((n&0x0000FFFF)<<16);
        n=((n&0xFF00FF00)>>8)|((n&0x00FF00FF)<<8);
        n=((n&0xF0F0F0F0)>>4)|((n&0x0F0F0F0F)<<4);
        n=((n&0xCCCCCCCC)>>2)|((n&0x33333333)<<2);
        n=((n&0xAAAAAAAA)>>1)|((n&0x55555555)<<1);
        return n;
    }
};

/***** Second Visit *****/
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

/***** First Visit *****/
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
