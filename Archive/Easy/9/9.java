class Solution {
    public boolean isPalindrome(int x)
    {
        if (x < 0)
            return false;

        if ((x + reverseNumber(x) == x * 2)
            return true;
        else
            return false;
    }

    private int reverseInt(int x)
    {
        int reverseNumber = 0;
        while ( x > 0){
            reverseNumber = reverseNumber * 10 + x % 10;
            x /= 10;
        }

        return reverseNumber;
    }
}
