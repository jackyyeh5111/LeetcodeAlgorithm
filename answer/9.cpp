/***** Second Visit *****/
/*
    reverse ALL num
    negative -> false
    use long to store reversed int
    T:O(logn)/S:O(1)
    -----------
    reverse HALF of num
    T:O(logn)/S:O(1)
*/
class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x<0) return false;
        long ans=0;
        int tmp=x;
        while(tmp) {ans=ans*10+tmp%10; tmp/=10;}
        return ans==x;
    }
};

class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x<0||(x%10==0&&x!=0)) return false;
        int rev=0;
        while(x>rev) {
            rev=rev*10+x%10;
            x/=10;
        }
        return rev==x||x==rev/10;
    }
};

/***** First Visit *****/
class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x<0) return false;
        long invert_x = 0;
        long input_x = (long)x;
        while (x!=0) {
            invert_x = invert_x*10+x%10;
            x/=10;
        }
        return input_x==invert_x;

    }
};
