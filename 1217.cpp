/*
    greedy
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int minCostToMoveChips(vector<int>& position)
    {
        int odd=0,even=0;
        for (int pos:position) {
            if (pos%2) odd++;
            else even++;
        }
        return min(odd,even);
    }
};
