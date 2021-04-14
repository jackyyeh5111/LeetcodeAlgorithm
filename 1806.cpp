/*
    Can we apply graph?
    T:O(n)/S:O(n)
*/
class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> graph(n,0);
        for (int i=0; i<n; ++i)
            graph[i]=i%2==0 ? i/2 : (i-1)/2+n/2;
        int cur=graph[1], ans=1;
        while (cur!=1) {cur=graph[cur]; ans++;}
        return ans;
    }
};
