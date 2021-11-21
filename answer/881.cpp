/*
    boat limit: 3
    ppl: [3,2,2,1]
    max possible boats: 4, i.e. length of array.
    2 ptr solution
    [1,2,2,3]
     ^   ^
    T:O(nlogn)/S:O(1)
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(),people.end());
        int l=0,r=people.size()-1,ans=0;
        while (l<r) {
            if (people[l]+people[r]<=limit) {
                l++; r--;
            }
            else r--;
            ans++;
        }
        return ans+(l==r);
    }
};