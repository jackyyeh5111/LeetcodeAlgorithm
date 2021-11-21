/*
    A = [2,7,11,15], B = [1,10,4,11]

    sort A then binary search on best larger number, which is the smallest num larger than b.
    T:O(nlogn+nlogn)/S:O(n)
*/
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B)
    {
        multiset<int> ms(A.begin(),A.end());
        vector<int> ans;
        for (int &b:B) {
            auto it=ms.lower_bound(b+1);
            if (it==ms.end()) it=ms.begin();
            ans.push_back(*it);
            ms.erase(it);
        }
        return ans;
    }
};
