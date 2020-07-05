/***************** Start from two endian *****************/
/*
    Explain about peak >= down ? -1:0
    when peak >= down, the candy for the peak still don't need to change.

    For example, [0, 1, 20, 9, 8, 7], for the first 5 number, we need to assign
    [1,2,3,2,1] candies. But when 7 comes up, we need to raise the value of the
    peak, which is 3 above, it need to be 4, [1,2,4,3,2,1]
    This solution here, make it to be [1,2,3,1,2,4], the sum are same. 
*/
class Solution {
public:
    int candy(vector<int>& ratings)
    {
        if (ratings.size() == 0) return 0;
        int ret = 1;
        int up = 0, down = 0, peak = 0;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i - 1] < ratings[i]) {
                peak = ++up;
                down = 0;
                ret += 1 + up;
            } else if (ratings[i - 1] == ratings[i])  {
                peak = up = down = 0;
                ret += 1;
            } else {
                up = 0;
                down++;
                ret += down;
                if (down>peak) ret+=1;
            }
        }

        return ret;
    }
};

/***************** Start from two endian *****************/
class Solution {
public:
    // T:O(n+n), S:O(n+n)
    int candy(vector<int>& ratings)
    {
        int size=ratings.size();
        vector<int> left(size,1);
        vector<int> right(size,1);
        for (int i=1; i<size; ++i) {
            if(ratings[i]>ratings[i-1])
                left[i]=left[i-1]+1;
            if(ratings[size-1-i]>ratings[size-i])
                right[size-1-i]=right[size-i]+1;
        }
        int sum=0;
        for (int i=0; i<size; ++i) sum+=max(left[i],right[i]);
        return sum;
    }
};
/***************** TLE *******************/
// T:O(n^2), S:O(n)
class Solution {
public:
    int candy(vector<int>& ratings)
    {
        /*
            in: 1 0 2
                2 1 2

            in: 1 2 2
                1 2 1

            in: 1 2 0 3
                1 2 1 2

            in: 1 2 2 3 1 1 0 3
                1 2 1 2 1 2 1 2

            visit num in ascendign order.
            T:O(nlogn+n),S:O(n)
            --------------
            in: 1 2 2 3 1 1 0 3
                1 2 1 2 1 1

            in: 0 1 2 3 2 1
                1 2 3 4 2 1
            greedy, T:O(n)?
        */
        int size=ratings.size();
        vector<int> ans(size,1);
        for (int i=1; i<size; ++i) {
            if (ratings[i]>ratings[i-1]) ans[i]=ans[i-1]+1;
            if (ratings[i]<ratings[i-1]&&ans[i-1]==1){
                ans[i-1]=2;
                int j=i-1;
                while(j>=1){
                    if (ratings[j-1]>ratings[j]&&ans[j-1]<=ans[j]) {
                        ans[j-1]=ans[j]+1;
                        j--;
                    }
                    else break;
                }
            }
        }
        int sum=0;
        for (int num:ans) {cout<<num<<","; sum+=num;}
        return sum;
    }
};
