class Solution {
public:
    /* 
        0 1 2 3 4 5
        1 1   1   2
     */
    int hIndex(vector<int>& cites) {
        vector<int> idxs(cites.size() + 1, 0);
        for (int cite : cites) {
            if (cite > cites.size())
                idxs[cites.size()]++;
            else
                idxs[cite]++;
        }

        // check counting idxs in reverse order
        int acc_cites = 0; // accumulate cites
        for (int i = cites.size(); i >= 0; i--) {
            acc_cites += idxs[i];
            if (acc_cites >= i) return i;
        }
        return 0;
    }
};

/* 
    We know h-index equals to array size at the top.
    
    citations = [3,0,6,1,5]
    [0 1 3 5 6]

    [5, 6]

    counting sort:
    0 1 2 3 4 5
    1 1   1   2
 */