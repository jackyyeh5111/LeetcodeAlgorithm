// T:O(n)/S:O(1)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int m=flowerbed.size(), ans=0;
        for (int i=0; i<m; ++i) {
            if (flowerbed[i]==0) {
                bool feasible=true;
                if (i>0&&flowerbed[i-1]==1) feasible=false;
                if (i<m-1&&flowerbed[i+1]==1) feasible=false;
                if (feasible) {ans++; flowerbed[i]=1;}
            }
        }
        return ans>=n;
    }
};
