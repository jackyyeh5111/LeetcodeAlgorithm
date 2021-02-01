/***** Fourth Visit *****/
/*
    [3,0,6,1,5]
    [0,1,3,5,6]
     1 2 3 4 5
        <--- checking
    sort: T:O(nlogn)
    sorted: T:O(n)/S:O(1)
    -----
    If sort could help, check bucket sort.
    1: 2
    2:
    3: 1
    4:
    5: 2
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> count(n+1,0);
        for (int num:citations) {
            if (num>n) count[n]++;
            else count[num]++;
        }
        int c=0;
        for (int i=n; i>=0; --i) {
            c+=count[i];
            if (c>=i) return i;
        }
        return 0;
    }
};

/***** Third Visit *****/
/*
    [0,1,3,5,6]
     0 1 2 3 4
     5 4 3 2 1
    T:O(nlogn+n) could. reduce linear probing to binary
    T:O(nlogn+logn)
    S:O(1)
*/
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        int n=citations.size();
        sort(citations.begin(),citations.end());
        for (int i=0; i<n; ++i) {
            if (citations[i]>=n-i)
                return n-i;
        }
        return 0;
    }
};

/***** Second Visit *****/
/*
    3 0 6 1 5
    0 1 3 5 6
    5 4 3 2 1
    sorting then find the index that cite>index+1
    T:O(nlogn)+O(n) or O(nlogn)+O(logn)/S:O(1)
    ------------
    0:1
    1:1
    2:
    3:1
    4:
    5:2
    bucket sort with 1 ~ n bins
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        int n=citations.size();
        vector<int> bins(n+1,0);
        for (int cite:citations) {
            if (cite>=n) bins[n]++;
            else bins[cite]++;
        }
        int total=0;
        for (int i=n; i>=0; --i) {
            total+=bins[i];
            if (total>=i) return i;
        }
        return 0;
    }
};

/***** First Visit *****/
/*
    3 0 6 1 5
    0 1 3 5 6
            ^
    sorting + traverse and start from big endian (for time saving)
    T:O(nlogn+n)/S:O(n) or S(1) whether modify the order of input
    citations
    -------------
    bucket sort to get T:O(n)
*/

/********* sorting T:O(nlogn) + T:O(logn) *********/
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end());
        int n=citations.size();
        int l=0, r=n-1;
        while(l<=r) {
            int mid=(l+r)/2;
            if (citations[n-mid-1]==mid+1) return mid+1;
            else if (citations[n-mid-1]>=mid+1) l=mid+1;
            else r=mid-1;
        }
        return r+1;
    }
};

/********* sorting T:O(nlogn) + T:O(n) *********/
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end());
        int n=citations.size();
        for (int i=n-1; i>=0; --i) {
            if (citations[n-i-1]>=i+1 ) return i+1;
        }
        return 0;
    }
};

/********* bucket sort T:O(n) *********/
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        unordered_map<int,int> m;
        int n=citations.size();
        for (int c:citations) {
            if (c>=n) m[n]++;
            else m[c]++;
        }
        int acc=0;
        for (int i=n; i>=1; --i) {
            acc+=m[i];
            if (acc>=i) return i;
        }
        return 0;
    }
};
