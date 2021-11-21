/*
    2-d array, check:
        1. DP --- cannot split into small problems then cumulatively solve it.
        2. backtracking --- kind of enumerate (v)
        3. Greedy --- divide & conquer, but we cannot split the 2-d array here.

    brute force
    enumerate all possible shift then find max overlap
    T:(4(n-1)^2 * checking overlap O(N^2))S:O(1)
    -----
    Reduce time complexity with an index hashmap to check bias
    T:O(n^2)/S:O(n^2) but worst case is still T:O(n^4)
*/
/***** directly check linear transform by indexing *****/
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        int ans=0;
        int rows=A.size(),cols=A[0].size();
        for (int v=-rows+1; v<rows; ++v) {
            for (int h=-cols+1; h<cols; ++h) {
                int cur_max=0;
                for (int i=0; i<rows; ++i) {
                    for (int j=0; j<cols; ++j) {
                        if (i+v>=rows||i+v<0||j+h>=cols||j+h<0) continue;
                        cur_max+=(A[i+v][j+h]+B[i][j]==2);
                    }
                }
                // cout<<"max:"<<cur_max<<",("<<v<<","<<h<<")"<<endl;
                ans=max(ans,cur_max);
            }
        }
        return ans;
    }
};

/***** Use a map to check same bias *****/
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        int rows=A.size(),cols=A[0].size();
        vector<int> indexA, indexB;
        for (int i=0; i<rows*cols; ++i) {
            if (A[i/rows][i%cols]==1)
                indexA.push_back(i / rows * 100 + i % cols);
        }
        for (int i=0; i<rows*cols; ++i) {
            if (B[i/rows][i%cols]==1)
                indexB.push_back(i / rows * 100 + i % cols);
        }
        unordered_map<int,int> m;
        for (auto a:indexA) {
            for (auto b:indexB) {
                m[a-b]++;
            }
        }
        int ans=0;
        for (auto item:m) ans=max(ans,item.second);
        return ans;
    }
};
