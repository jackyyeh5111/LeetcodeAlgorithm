/*
      2 1 2 4 2 2
      5 2 6 2 3 2
    2:1 1 1 1 1 1
    5:1
    1:  1
    6:    1
    4:      1
    3:        1

    Use a hash map with k:val, v:[a,b,a|b] denotes the counter of A / B / A|B respectively.
    First check if any val happens n times.
    T:O(n)/S:O(k), k denotes the max possible val of domino, which is at most 6.
    -> T:O(n)/S:O(1)
    -----
    Just check A[0]/B[0]
    T:O(n)/S:O(1)
*/
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B)
    {
        int n=A.size();
        vector<vector<int>> table(7,vector<int>(3,0));
        for (int i=0; i<n; ++i) {
            table[A[i]][0]++;
            table[B[i]][1]++;
            if (A[i]==B[i]) table[A[i]][2]++;
            else {
                table[A[i]][2]++;
                table[B[i]][2]++;
            }
        }
        int ans=n; bool found=false;
        for (int i=1; i<=6; ++i) {
            if (table[i][2]==n) {
                ans=min(ans,n-max(table[i][0],table[i][1]));
                found=true;
            }
        }
        return found?ans:-1;
    }
};

int minDominoRotations(vector<int>& A, vector<int>& B) {
  auto top = A[0], bot = B[0], top1 = 0, bot1 = 0, top2 = 0, bot2 = 0;
  for (auto i = 0; i < A.size(); ++i) {
    if (A[i] != top && B[i] != top) top = 0;
    if (A[i] != bot && B[i] != bot) bot = 0;
    top1 += A[i] == top;
    bot1 += B[i] == top;
    top2 += A[i] == bot;
    bot2 += B[i] == bot;
  }
  return top || bot ? min(A.size() - max(top1, bot1), A.size() - max(top2, bot2)) : -1;
}
