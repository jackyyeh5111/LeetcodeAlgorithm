/*
    search problem
    -----
    brute force: enumerate all pairs
    T:O(n^2)/S:O(n)
    -----
    binary search
    T:O(nlogn)/S:O(n)
*/
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z)
    {
        vector<vector<int>> ans;
        for (int x=1; x<=1000; ++x) {
        	int l=1, r=1000;
        	while (l<=r) {
        		int mid=(l+r)/2;
        		int t=customfunction.f(x,mid);
        		if (t==z){
        			ans.push_back({x,mid});
                    break;
        		}
        		else if (t<z) l=mid+1;
        		else r=mid-1;
        	}
        	if (r==-1) break;
        }
        return ans;
    }
};
