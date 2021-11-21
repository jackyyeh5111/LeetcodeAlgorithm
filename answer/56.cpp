/***** Sixth Visit *****/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        for (int i=0; i<n; ++i) {
            int rb=intervals[i][1];
            int j=i+1;
            while (j<n&&rb>=intervals[j][0])
                rb=max(rb,intervals[j++][1]);
            ans.push_back({intervals[i][0],rb});
            i=j-1;
        }
        return ans;
    }
};

/***** Fourth Visit *****/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int i=0, n=intervals.size();
        while (i<n) {
            int j=i+1, up=intervals[i][1];
            while (j<n&&intervals[j][0]<=up) {
                up=max(up,intervals[j++][1]);
            }
            ans.push_back({intervals[i][0],up});
            i=j;
        }
        return ans;
    }
};

/***** Third Visit *****/
/*
    2 ptr greedy approach
    greedy -> Always sort first.
    T:O(nlogn)/S:O(n)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
            if (a[0]!=b[0]) return a[0]<b[0];
            else return a[1]<b[1];
        });
        int n=intervals.size(), l=0;
        while (l<n) {
            int r=l+1, ceil=intervals[l][1];
            while (r<n&&ceil>=intervals[r][0]) ceil=max(ceil,intervals[r++][1]);
            ans.push_back(vector<int>{intervals[l][0],ceil});
            l=r;
        }
        return ans;
    }
};

/***** Second Visit *****/
/*
    divide & conquer
    T(n)=2T(n/2)+O(n)=O(nlogn)/S:O(logn)
    -----
    Array: could sorting help? YES!
    sort then greedy merge incoming pair if i.second > i+1.first.
    T:O(nlogn+n)/S:O(n) with extra return array.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ret;
        for(auto interval:intervals) {
            if (ret.size()==0) ret.push_back(interval);
            else {
                if (ret.back()[1]>=interval[0])
                    ret.back()[1]=max(ret.back()[1],interval[1]);
                else ret.push_back(interval);
            }
        }
        return ret;
    }
};

/***** First Visit *****/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // brute force O(n^2)
        // sorting then greedy
        // T:O(nlogn)+O(n)
        if (intervals.size()==0) return vector<vector<int>>{};
        sort(intervals.begin(), intervals.end(), [](auto& a, auto&b){
            return a[0]<b[0];
        });
        vector<vector<int>> ans{intervals[0]};
        for (int i=1; i<intervals.size(); ++i) {
            if (intervals[i][0]<=ans[ans.size()-1][1])
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};
