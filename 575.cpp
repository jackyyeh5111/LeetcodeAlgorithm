class Solution {
public:
    int distributeCandies(vector<int>& candyType)
    {
        unordered_set<int> s(candyType.begin(),candyType.end());
        return min((int)candyType.size()/2,(int)s.size());
    }
};
