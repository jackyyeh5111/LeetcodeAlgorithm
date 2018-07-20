class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        if ((x + reverse_integer(x)) == x * 2)
            return true;
        else
            return false;
    }
private:
    int reverse_integer(int x)
    {
        int reverse = 0;
        while(x>0){
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return reverse;
    }
};
