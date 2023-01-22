/* 
    dfs3 比 dfs2, dfs1 簡潔多了! 這自己想的～～
 */

class Solution {
public:
    int ans = 0;
    int maxLength(vector<string>& arr) {
        for (int i = 0; i < arr.size(); ++i)
            dfs(arr, 0, i, 0);
        return ans;
    }

    void dfs(const vector<string>& arr, int bitmask, int idx, int seq_len){
        if (idx == arr.size()) return;
        for (const auto ch : arr[idx]) {
            int tgt_bit = (ch - 'a');
            if (bitmask >> tgt_bit & 1) 
                return;
            bitmask += 1 << tgt_bit;
        }

        seq_len += arr[idx].size();
        ans = max(seq_len, ans);
        
        for (int i = idx + 1; i < arr.size(); ++i)
            dfs(arr, bitmask, i, seq_len);
    }
};
