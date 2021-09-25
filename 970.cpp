/*
    k = x^i + y^j for some integers i >= 0 and j >= 0.
    k <= bound
    return unique nums

    1 2 4 8
    ^
    1 3 9
    ^
    T:O(logm * logn) 2 pass / S:O(logm * logn)

*/
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        if (x>y) swap(x,y);
        int i=1;
        while (i<bound) {
            int j=1;
            while (i+j<=bound) {
                s.insert(i+j);
                j*=y;
                if (j==1) break;
            }
            i*=x;
            if (i==1) break;
        }
        vector<int> ans(s.begin(),s.end());
        return ans;
    }
};
