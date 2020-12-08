/***** Third Visit *****/
/*
    Array: 2 ptr solutions
    [1,  2,  3, 4, 5]
    [3,  4,  5, 1, 2]
    -2, -2, -2, 3, 3
     ^             ^
     T:O(n)/S:O(1)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int l=0, r=cost.size()-1, remain=gas[r]-cost[r];
        while (l<=r) {
            if (remain<0&&r<1) return -1;
            else if (remain<0) {
                r--;
                remain+=gas[r]-cost[r];
            }
            else {
                remain+=gas[l]-cost[l];
                l++;
            }
        }
        return remain>=0?r:-1;
    }
};

/***** Second Visit *****/
/*
    1  2  3  4  5
    3  4  5  1  2
    -------------
    -2 -2 -2 3  3
        ^       ^
           ^ ^
    ------
    Array
    1. could sort help?
      -> could bucket sort help?
    2. binary search
    3. 2 ptr solution (V)
    4. running ptr.
    5. 2-D array
      -> DP/greedy/divide&conquer
    -----
    We adopt 2 ptr solution, kind of greedy
    r=n-1 means where we start, l=0 denotes our running ptr. If we have negative gas, roll back r.
    after iteration, check the remaining gas.
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int l=0, r=cost.size()-1;
        int remain=gas[r]-cost[r];
        while (l<r) {
            if (remain<0){r--; remain+=gas[r]-cost[r];}
            else {remain+=gas[l]-cost[l]; l++;}
        }
        return remain>=0?r:-1;
    }
};

/***** First Visit *****/
class Solution {
public:
    // T:O(n), S:O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        /*
        sum is used to check if circuit exists.
        if sum < 0, there's no circuit in these stations, thus we consider
        start at the next pointn, i.e. index+1;
        */
        int sum=0, minSum=0, index=0;
        int size=gas.size();
        for (int i=0; i<size; ++i) {
            sum+=gas[i]-cost[i];
            if(sum<minSum) {
                minSum=sum;
                index=(i+1)%size;
            }
        }
        return sum>=0?index:-1;
    }
};


class Solution {
public:
    // T:O(n), S:O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        /*
            1  2  3  4  5
            3  4  5  1  2
           -2 -2 -2  3  3
                  ^  ^

           2  3  4
           3. 4. 3
          -1 -1  1
          two ptr: l, r. start on r and end on l. stop when l+1==r
        */
        int l=0, r=cost.size()-1;
        int sum = gas[r]-cost[r];
        while(l<r) {
            // cout<<l<<","<<r<<endl;
            if(sum>=0) {sum+=gas[l]-cost[l]; l++;}
            else {r--; sum+=gas[r]-cost[r];}
        }
        // cout<<sum<<endl;
        return sum>=0?r:-1;
    }
};
