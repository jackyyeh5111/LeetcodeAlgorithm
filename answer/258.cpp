/***** Second Visit *****/
/*
    38 11 2
    50 5
    134 8
    178 16 7
    97698 39 12 3
    9 possible answers: 1-9 except input num less than 10
*/
class Solution {
public:
    int addDigits(int num)
    {
        if (num<9) return num;
        int ans=num%9;
        return ans==0?9:ans;
    }
};

/***** First Visit *****/
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
