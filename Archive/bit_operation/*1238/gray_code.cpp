#include <vector>
class Solution {
public:
    vector<int> circularPermutation(int n, int start)
    {
        vector<int> result;
        for (int i=0; i<(1<<n); ++i){
            int gray_code = i^(i>>1);
            result.push_back(start^gray_code);
        }
        return result;
    }
};
