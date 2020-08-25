/*************** Second Visit ***************/
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans{1};
        for (int i=0; i<rowIndex; ++i) {
            vector<int> tmp{1};
            for (int j=0; j<ans.size()-1; ++j) {
                tmp.push_back(ans[j]+ans[j+1]);
            }
            tmp.push_back(1);
            swap(tmp,ans);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex+1,1);
        for (int i=0; i<=rowIndex; ++i) {
            int prev=ans[0];
            for (int j=1; j<i; ++j) {
                int tmp=ans[j];
                ans[j]+=prev;
                prev=tmp;
            }
        }
        return ans;
    }
};

/*************** Second Visit ***************/
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        /*
            use 1d dp
            T:O((rowIndex+1)^2), S:O(1)
        */
        vector<int> ans(rowIndex+1,1);
        for(int row=0; row<=rowIndex; ++row) {
            int prev=ans[0];
            for (int col=1; col<row; ++col) {
                int tmp=ans[col];
                ans[col]+=prev;
                prev=tmp;
            }
        }
        return ans;
    }
};
