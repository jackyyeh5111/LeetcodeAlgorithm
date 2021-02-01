class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        sort(boxTypes.begin(),boxTypes.end(),[](auto a, auto b){
            return a[1]>=b[1];
        });
        int cur=0, ans=0, p=0;
        while (p<boxTypes.size()) {
            if (cur+boxTypes[p][0]<=truckSize) {
                cur+=boxTypes[p][0];
                ans+=boxTypes[p][0]*boxTypes[p][1];
                p++;
            }
            else {
                ans+=(truckSize-cur)*boxTypes[p][1];
                break;
            }
        }
        return ans;
    }
};