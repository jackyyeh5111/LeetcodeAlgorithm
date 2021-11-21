/*
    find low/high's largest decimal digit.
    enumerate all possible nums and check if inside the range.
    T:O(logn)/S:O(logn)
*/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high)
    {
        int ln=to_string(low).length();
        int hn=to_string(high).length();
        vector<int> ans;
        for (;ln<=hn;++ln) {
            for (int i=1; i<10; ++i) {
                int num=i,k=i,j=1;
                for (; j<ln&&k<9; ++j) {
                    num=num*10+(++k);
                }
                // cout<<num<<","<<ln<<endl;
                if (j==ln&&num>=low&&num<=high)
                    ans.push_back(num);
            }
        }
        return ans;
    }
};
