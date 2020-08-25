/********** Second Visit **********/
/*
    1 2 ... sqrt(n)
    recursive with cache memorization
    Further improve with static cache for all test cases
*/

class Solution {
public:
    int numSquares(int n)
    {
        static unordered_map<int,int> table;
        if (table.find(n)!=table.end()) return table[n];
        int m=sqrt(n);
        if (m*m==n) { table[n]=1; return 1;}
        int ans=INT_MAX;
        for (int i=1; i<=m; ++i) {
            // if (n<i*i) continue;
            ans=min(ans,numSquares(n-i*i)+1);
        }
        table[n]=ans;
        return ans;
    }
};

class Solution {
public:
    int numSquares(int n)
    {
        // T:O(n^2)/S:O(1)
        vector<int> table(n+1,INT_MAX);
        table[0]=0;
        for (int i=1; i<=n; ++i) {
            int j=1;
            while(i-j*j>=0) {
                table[i]=min(table[i],table[i-j*j]+1);
                j++;
            }
        }
        return table[n];
    }
};

/********** First Visit **********/
/***** dp solve ******/
class Solution {
public:
    int numSquares(int n)
    {
        /*
            dp ?
            13 9 4
            14 9 5
                 5 4 1
            12 9 3 <----- dp fail
                 1 1 1
            12 4 4 4 <----- ans

            brute force + dp, i.e. iterate all possible combines in dp.
        */
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for (int i=1; i<=n; ++i) { //O(n)
            int j=1;
            while(i-j*j>=0) {dp[i]=min(dp[i-j*j]+1,dp[i]); j++;} //O(n/2)
            // cout<<dp[i]<<",";
        }
        return dp[n];
    }
};

/***** Math ******/
// Based on Lagrange's Four Square theorem, there
// are only 4 possible results: 1, 2, 3, 4.
int is_square(int n)
{
    int sqrt_n = (int)(sqrt(n));
    return (sqrt_n*sqrt_n == n);
}

int numSquares(int n)
{
    // If n is a perfect square, return 1.
    if(is_square(n)) return 1;

    // The result is 4 if and only if n can be written in the
    // form of 4^k*(8*m + 7).
    // Legendre's three-square theorem states that a natural number can be
    // represented as the sum of three squares of integers if and only if n is
    // NOT of the form 4^k*(8*m + 7) for nonnegative integers k and m.
    while ((n & 3) == 0) n >>= 2;// n%4 == 0
    if ((n & 7) == 7) return 4;// n%8 == 7

    // Check whether 2 is the result.
    int sqrt_n = (int)(sqrt(n));
    for(int i = 1; i <= sqrt_n; i++) {
        if (is_square(n - i*i)) return 2;
    }

    return 3;
}

/***** BFS ******/
int numSquares(int n)
{
    if (n <= 0) return 0;

    // perfectSquares contain all perfect square numbers which
    // are smaller than or equal to n.
    vector<int> perfectSquares;
    // cntPerfectSquares[i - 1] = the least number of perfect
    // square numbers which sum to i.
    vector<int> cntPerfectSquares(n);

    // Get all the perfect square numbers which are smaller than
    // or equal to n.
    for (int i = 1; i*i <= n; i++) {
        perfectSquares.push_back(i*i);
        cntPerfectSquares[i*i - 1] = 1;
    }

    // If n is a perfect square number, return 1 immediately.
    if (perfectSquares.back() == n) return 1;

    // Consider a graph which consists of number 0, 1,...,n as
    // its nodes. Node j is connected to node i via an edge if
    // and only if either j = i + (a perfect square number) or
    // i = j + (a perfect square number). Starting from node 0,
    // do the breadth-first search. If we reach node n at step
    // m, then the least number of perfect square numbers which
    // sum to n is m. Here since we have already obtained the
    // perfect square numbers, we have actually finished the
    // search at step 1.
    queue<int> searchQ;
    for (auto& i : perfectSquares) searchQ.push(i);

    int currCntPerfectSquares = 1;
    while (!searchQ.empty())
    {
        currCntPerfectSquares++;

        int searchQSize = searchQ.size();
        for (int i = 0; i < searchQSize; i++){
            int tmp = searchQ.front();
            // Check the neighbors of node tmp which are the sum
            // of tmp and a perfect square number.
            for (auto& j : perfectSquares) {
                // We have reached node n.
                if (tmp + j == n) return currCntPerfectSquares;
                else if ((tmp + j < n) && (cntPerfectSquares[tmp + j - 1] == 0))
                {
                    // If cntPerfectSquares[tmp + j - 1] > 0, this is not
                    // the first time that we visit this node and we should
                    // skip the node (tmp + j).
                    cntPerfectSquares[tmp + j - 1] = currCntPerfectSquares;
                    searchQ.push(tmp + j);
                }
                // We don't need to consider the nodes which are greater than n.
                else if (tmp + j > n) break;
            }
            searchQ.pop();
        }
    }

    return 0;
}
