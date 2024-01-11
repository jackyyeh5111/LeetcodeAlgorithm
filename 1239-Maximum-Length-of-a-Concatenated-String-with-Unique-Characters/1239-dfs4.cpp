/* 
    dfs4 先算出所有 masks! 可以更省時間
 */
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> masks;
        for (string str : arr) {
            int mask = 0;
            bool replicate = false;
            for (char ch : str) {
                int bit = 1 << (ch - 'a');
                if (mask & bit) {
                    replicate = true;
                    break;
                }
                mask += bit;
            }
            if (!replicate)
                masks.push_back(mask);
        }

        for (int i = 0; i < masks.size(); i++)
            dfs(masks, i, 0);
        return ans;
    }
    
    int ans = 0;
    void dfs(const vector<int> &masks, int pos, int bit_mask) {
        if (pos == masks.size())
            return;
        int N = masks.size();
        bit_mask |= masks[pos];
        
        int count = 0;
        int tmp_bit_mask = bit_mask;
        while(tmp_bit_mask) {
            tmp_bit_mask &= tmp_bit_mask - 1;
            count++;
        }
        ans = max(ans, count);
        
        for (int i = pos + 1; i < N; i++) {
            if (masks[i] & bit_mask)
                continue;
            dfs(masks, i, bit_mask);
        }
    }
};

/* 
    Clarification:
        1. only lowercase chars

    ab -> 1100
    cd -> 0011
 */