/*
    1 2 3 4 5, prefix sum
    segment tree?
    0 1 2 3 4 5 6 7
    1 2 3 4 5 6 7 8
    T:O(n) / T:O(logn) / 2 pass T:O(logn)
    _ _ ___ _______
    fenwick tree (BINARY INDEX TREE)
    How to find the last 1 bit of x?
    ANS: x&(-x)
*/

class NumArray {
public:
    int seg[30000]={0};
    int size=30000;

    // T:O(nlogn)
    NumArray(vector<int>& nums) {
        size=nums.size();
        for (int i=0; i<size; ++i) {
            update(i,nums[i]);
        }
    }

    // T:O(logn)
    void update(int index, int val) {
        int diff=val-query(index)+query(index-1);
        index+=1;
        while (index<=size) {
            seg[index-1]+=diff;
            index+=index&(-index);
        }
    }

    // T:O(logn)
    int sumRange(int left, int right) {
        return query(right)-query(left-1);
    }

    // T:O(logn)
    int query(int index) {
        int ret=0;
        index+=1;
        while (index>0) {
            ret+=seg[index-1];
            index-=index&(-index);
        }
        return ret;
    }
};

// power of 2 decomposition
class NumArray {
public:
    int seg[30000]={0};
    int n=30000;
    // T:O(n)
    NumArray(vector<int>& nums) {
        n=nums.size();
        int csum=0;
        for (int i=0; i<n; ++i) {
            csum+=nums[i];
            seg[i]=csum;
            if (!(i&(i+1))) csum=0;
        }
    }

    // T:O(logn+n)
    void update(int index, int val) {
        int diff=0;
        if (index<2||!(index&(index-1))) diff=val-seg[index];
        else diff=val-seg[index]+seg[index-1];
        while (index<n) {
            seg[index]+=diff;
            if (!(index&(index+1))) break;
            index++;
        }
    }

    // T:O(logn+n)
    int sumRange(int left, int right) {
        int rval=seg[right];
        int r=1;
        while (r<right+1) {
            rval+=seg[r-1];
            r=r<<1;
        }
        int l=1, lval=left==0?0:seg[left-1];
        while (l<left) {
            lval+=seg[l-1];
            l=l<<1;
        }
        return rval-lval;
    }
};
