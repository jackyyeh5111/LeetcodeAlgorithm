/***** Second Visit *****/
/*
    Use an unordered_map to record all nums and further reduce searching complexity to T:O(1)
    the answer is at most n, so we have at most 2n numbers to search.
    T:O(n)/S:O(n)
    -----
    2,3,1,7,8,9,10
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n=nums.size(), ans=1;
        if (n<=1) return n;
        unordered_map<int,int> m;
        for (int num:nums) m[num]=-1;
        for (int num:nums) {
            if (m[num]!=-1) continue;
            m[num]=1;
            for (int i=1; i<n; ++i) {
                if (m.count(num+i)==0) break;
                else if (m[num+i]!=-1) {
                    m[num]+=m[num+i];
                    m[num+i]=0;
                    break;
                }
                else {
                    m[num]++;
                    m[num+i]=0;
                }
            }
            ans=max(ans,m[num]);
        }
        return ans;
    }
};

/***** First Visit *****/
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        /*
        despite looking like O(n \cdot n)O(n⋅n) complexity, the nested loops
        actually run in O(n + n) = O(n)O(n+n)=O(n) time. All other computations
        occur in constant time, so the overall runtime is linear.

        Just keep in mind use UNION(set) to reduce searching complexity to O(1)
        */
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for (int num:nums) {
            if(s.find(num-1)==s.end()&&num!=INT_MAX) {
                int tmp=1; num++;
                while(num!=INT_MAX&&s.find(num++)!=s.end()) tmp++;
                ans=max(ans,tmp);
            }
        }
        return ans;
    }
};
