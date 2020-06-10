class Solution {
public:
    // T: O(n), S:O(n)
    vector<int> sum;
    Solution(vector<int>& w) {
        sum=w;
        for (int i=1; i<w.size(); ++i)
            sum[i]=sum[i-1]+w[i];
    }

    int pickIndex() {
        int idx = rand()%sum[sum.size()-1];
        int l=0; int r=sum.size()-1;
        while (l<r) {
            int mid = (l+r)/2;
            if (idx<sum[mid]) r=mid;
            else l=mid+1;
        }
        return r;
    }
};


w: 2 5 4 6
s: 2 7 11 17
rand 2 -> 1
rand 0~1 -> 0

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
