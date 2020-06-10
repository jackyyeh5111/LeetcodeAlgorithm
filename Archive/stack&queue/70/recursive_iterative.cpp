#include <map>
class Solution {
public:
    // Time Limited Expired
    /*
    int climbStairs(int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        return climbStairs(n-1)+climbStairs(n-2);
    }
    */
    // Spatial Complexity: O(n)
    /*
    int climbStairs(int n) {
        map<int, int> table;
        table[1]=1; table[2]=2;
        int result=0; int count=3;
        while(count<=n-1) {
            table[count]=table[count-1]+table[count-2];
            count++;
        }
        if(n<3) return table[n];
        else return table[n-1]+table[n-2];
    }
    */
    int climbStairs(int n) {
        if(n<3) return n;

        int first=1; int second=2;
        int count=3;
        while(count<=n-1) {
            int result = first+second;
            first=second; second=result;
            count++;
        }

        return first+second;
    }
};
