/*
    Just iteratively check L/R with a running sum L: -90, r: +90
    Check orientation only will fail. We must include position checking.
    -----
    1. Calculate the final vector of how the robot travels after executing all instructions once - it consists of a change in position plus a change in direction.
    2. The robot stays in the circle iff (looking at the final vector) it changes direction (ie. doesn't stay pointing north), or it moves 0.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    bool isRobotBounded(string instructions)
    {
        int x=0,y=0,dir=0;
        for(char c:instructions) {
            if (c=='L') {dir--; dir=(dir+4)%4;}
            else if (c=='R') {dir++; dir=(dir+4)%4;}
            else {
                if (dir==0) y++;
                else if(dir==1) x++;
                else if(dir==2) y--;
                else x--;
            }
        }
        return dir!=0||(x==0&&y==0);
    }
};
