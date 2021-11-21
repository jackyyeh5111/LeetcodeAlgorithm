/*
    sorting problem
    Cost: min(left_length,right_length)
    return it modulo 10^9 + 7

    brute force:
    online sorting
    T:O(nlogn)/S:O(n)
    -----
    Reduce the problem to be:
    for each num, find its kth largest from 0th to ith num and cumulatively add cost. min(k,i-k)
    In practice, we are going to do binary search and insertion on an sorted array. So the actualy TC would still be T:O(n^2) while producing sorted array.
    -----
    Segment Tree -> Binary Indexed Tree.
    refer: https://www.hackerearth.com/practice/notes/binary-indexed-tree-or-fenwick-tree/

    get function
    1111 15
    1110 14
    1100 12
    1000 8
    0000 0

    update function
    1101 13
    1110 14
   10000 16
   T:O(nlogm)/S:O(m)
*/

class Solution {
public:
    int createSortedArray(vector<int>& instructions)
    {
        int table[100001]={0}, ans=0, m=pow(10,9)+7, n=instructions.size();
        for (int i=0; i<n; ++i) {
            int num=instructions[i];
            ans=(ans+min(i-get(table,num),get(table,num-1)))%m;
            update(table,num);
        }
        return ans;
    }

    void update(int *table, int x)
    {
        while (x<100001) {
            table[x]+=1;
            x+=x&(-x);
        }
    }

    int get(int *table, int x)
    {
        int ret=0;
        while (x>0) {
            ret+=table[x];
            x-=x&(-x);
        }
        return ret;
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions)
    {
        multiset<int> ms;
        int ans=0;
        for (int num:instructions) {
            int k=distance(ms.begin(),lower_bound(ms.begin(),ms.end(),num));
            int n=ms.count(num), total=ms.size();
            int cost=min(min(k,total-k),min(k+n,total-k-n));
            ans=(ans+cost)%1000000007;
            ms.insert(num);
        }
        return ans;
    }
};
