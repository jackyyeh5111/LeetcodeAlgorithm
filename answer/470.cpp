// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

/*
    rand7: 1-7 -> 0-6 -> 0-1 -> 0-9 -> 1-10
    This solution will cause limit option, we only have 7 nums in range 0-10.
    --------
    create a list 1-5, each of them add 5 within 50% probability.
*/
class Solution {
public:
    int rand10()
    {
        int i=7,j=6;
        while(i>6) i=rand7(); // i: 1 2 3 4 5 6
        while(j>5) j=rand7(); // j: 1 2 3 4 5
        if (i%2) return j;
        else return j+5;
    }
};
