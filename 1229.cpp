/*
    sort + 2 ptr
    T:O(nlogn)/S:O(n)
    -----
    NEAT CODE
    We can see that i,j will never go left, thus we can directly apply 2 ptr solution. Check each possible pair and find overlay while going right.
    T:O(nlogn)/S:O(n)
*/

// Neat Code
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration)
    {
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());
        int i=0, j=0, m=slots1.size(), n=slots2.size();
        while (i<m&&j<n) {
            int maxStart=max(slots1[i][0],slots2[j][0]);
            int minEnd=min(slots1[i][1],slots2[j][1]);
            if (maxStart+duration<=minEnd) return {maxStart,maxStart+duration};
            else if (slots1[i][1]<slots2[j][1]) i++;
            else j++;
        }
        return {};
    }
};

//
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration)
    {
        sort(slots1.begin(),slots1.end(),[](auto &a, auto &b){
            if (a[0]==b[0]) return a[1]<b[1];
            else return a[0]<b[0];
        });
        sort(slots2.begin(),slots2.end(),[](auto &a, auto &b){
            if (a[0]==b[0]) return a[1]<b[1];
            else return a[0]<b[0];
        });
        int i=0, j=0, m=slots1.size(), n=slots2.size();
        while (i<m&&j<n) {
            while (i<m&&slots1[i][0]+duration>slots1[i][1]) i++;
            if (i==m) break;
            while (j<n&&slots2[j][1]<slots1[i][0]) j++;
            if (j==n) break;
            int maxStart=max(slots1[i][0],slots2[j][0]);
            int minEnd=min(slots1[i][1],slots2[j][1]);
            if (maxStart+duration<=minEnd) return {maxStart,maxStart+duration};
            else i++;
        }
        return {};
    }
};
