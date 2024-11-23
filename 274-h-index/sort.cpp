class Solution {
public:
    int hIndex(vector<int>& cite) {
        sort(cite.begin(), cite.end());
        for (int i = 0; i < cite.size(); i++) {
            if (cite[i] >= cite.size() - i)
                return cite.size() - i;
        }
        return 0;
    }
};

/* 
    citations = [3,0,6,1,5]
    [0 1 3 5 6]

    [5, 6]
 */