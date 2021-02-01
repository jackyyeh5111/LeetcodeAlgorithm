/***** Third Visit *****/
/*
        [2,1,4,7,3,2,5]
    up   0 0 1 2 0 0 1  0   1
    down 0 1 0 0 1 2 0  1   0
    ans.     2     5

         [7,4,8]
    up    0 0 1  0
    down  0 1 0  1
    ans
         [0,0,1,0,0,1,1,1,1,1]
    up    0 0 1 1
    down  0 0 0 1

*/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int up=0, down=0, n=arr.size(), ans=0;
        for (int i=1; i<n; ++i) {
            if (arr[i]<arr[i-1]) down++;
            else if (arr[i]>arr[i-1]) up++;
            else up=down=0;
            if (arr[i]<arr[i-1]&&(i==n-1||arr[i]<=arr[i+1])) {
                if (up>0&&down>0)
                    ans=max(ans,up+down+1);
                up=down=0;
            }
        }
        return ans;
    }
};

/***** Second Visit *****/
/*
          [2, 1, 4, 7, 3, 2, 5]
    up:    0  0  1  2  2  2
    down:  0  1  0  0  1  2
*/

class Solution {
public:
    int longestMountain(vector<int>& arr)
    {
        int n=arr.size(), ans=0;
        vector<int> inc(n,0);
        vector<int> dec(n,0);
        for (int i=1; i<n; ++i) {
            if (arr[i]>arr[i-1]) inc[i]=inc[i-1]+1;
            if (arr[n-1-i]>arr[n-i]) dec[n-1-i]=dec[n-i]+1;
            if (inc[i]>0&&dec[i]>0)
                ans=max(ans,inc[i]+dec[i]+1);
            if (inc[n-1-i]>0&&dec[n-i-1]>0)
                ans=max(ans,inc[n-1-i]+dec[n-1-i]+1);
        }
        return ans;
    }
};

class Solution {
public:
    int longestMountain(vector<int>& arr)
    {
        int n=arr.size(), up=0,down=0,ans=0;
        for (int i=1; i<n; ++i) {
            if ((down>0&&arr[i]>arr[i-1])||arr[i]==arr[i-1]) {down=0; up=0;}
            up+=arr[i]>arr[i-1];
            down+=arr[i]<arr[i-1];
            if (up&&down) ans=max(ans,up+down+1);
        }
        return ans;
    }
};

/***** First Visit *****/
/*
    2,1,4,7,3,2,5
    1 1 2 3 1 1 2 >> a
    2 1 1 3 2 1 1 << b
    record bi-directional increasing order
    if both side are larger than 1, it might be an answer with a+b-1
    T:O(n)/S:O(n) 2 pass
    -----
    0 1 0 1
    1 2 1
      2 1 1
    start from both endian
    T:O(n)/S:O(n) 1 pass
    -----
    brute force, treat each position as a peak of mountain and check its length
    T:O(n^2)/S:O(1)
    -----
    Count up length and down length.
    Both up and down length are clear to 0 when A[i - 1] == A[i] or down > 0 && A[i - 1] < A[i].
    T:O(n)/S:O(1)
*/
// T:O(n)/S:O(n) 2 pass
class Solution {
public:
    int longestMountain(vector<int>& A)
    {
        int n=A.size();
        vector<int> right(n,1);
        vector<int> left(n,1);
        for (int i=1; i<n; ++i) {
            if (A[i]>A[i-1]) right[i]=right[i-1]+1;
            if (A[n-i-1]>A[n-i]) left[n-i-1]=left[n-i]+1;
        }
        int ans=0;
        for (int i=0; i<n; ++i) {
            if (right[i]>1&&left[i]>1) ans=max(ans,left[i]+right[i]-1);
        }
        return ans;
    }
};

// T:O(n)/S:O(n) 1 pass
class Solution {
public:
    int longestMountain(vector<int>& A)
    {
        int n=A.size();
        vector<int> right(n,1);
        vector<int> left(n,1);
        int ans=0;
        for (int i=1; i<n; ++i) {
            if (A[i]>A[i-1]) right[i]=right[i-1]+1;
            if (A[n-i-1]>A[n-i]) left[n-i-1]=left[n-i]+1;
            if (right[i]>1&&left[i]>1) ans=max(ans,left[i]+right[i]-1);
            if (right[n-i-1]>1&&left[n-i-1]>1) ans=max(ans,left[n-i-1]+right[n-i-1]-1);
        }
        return ans;
    }
};

// T:O(n)/S:O(1) up and down counting
class Solution {
public:
    int longestMountain(vector<int>& A)
    {
        int n=A.size(), up=0,down=0,ans=0;
        for (int i=1; i<n; ++i) {
            if ((down>0&&A[i]>A[i-1]) || (A[i]==A[i-1])) {down=0; up=0;}
            up+=A[i]>A[i-1];
            down+=A[i]<A[i-1];
            if (up&&down) ans=max(ans,up+down+1);
        }
        return ans;
    }
};
