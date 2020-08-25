/*
    If an integer is like 100a+10b+c, then
    (100a+10b+c)%9=(a+99a+b+9b+c)%9=(a+b+c)%9
*/
class Solution {
public:
    int addDigits(int num)
    {
       return num==0 ? 0 : 1+(num-1)%9;
    }
};

class Solution {
public:
    int addDigits(int num)
    {
        while(num/10) {
            int tmp=0;
            while(num) {
                tmp+=num%10;
                num/=10;
            }
            num=tmp;
        }
        return num;
    }
};
