/*
    Same to problem 7.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int myAtoi(string str)
    {
        int i=0, n=str.length();
        while(str[i]==' ') i++;
        int ans=0; bool pos=1;
        if (str[i]=='-') {pos=0; i++;}
        else if (str[i]=='+') {pos=1; i++;}
        while(isdigit(str[i])) {
            if (pos&&(ans>INT_MAX/10||(ans==INT_MAX/10&&str[i]-'0'>7)))
                return INT_MAX;
            if (!pos&&(ans>INT_MAX/10||(ans==INT_MAX/10&&str[i]-'0'>=8)))
                return INT_MIN;
            ans=ans*10+(str[i++]-'0'); // may cause overflow
        }
        return pos?ans:-1*ans;
    }
};
